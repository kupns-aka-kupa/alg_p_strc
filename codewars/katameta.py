import bs4
import requests
from yaml import load, dump
import re
import os
import time
from selenium import webdriver
from selenium.webdriver.firefox.firefox_binary import FirefoxBinary
from selenium.webdriver.firefox.options import Options

try:
    from yaml import CLoader as Loader, CDumper as Dumper
except ImportError:
    from yaml import Loader, Dumper

SCROLL_PAUSE_TIME = 2

cap = webdriver.common.desired_capabilities.DesiredCapabilities().FIREFOX
cap["marionette"] = False

options = Options()
options.log.level = "trace"
# options.add_argument('--headless')

BROWSER_BINARY_PATH = '/usr/bin/firefox'
DRIVER_BINARY_PATH = '/usr/local/bin/geckodriver'
BROWSER_CONFIG = {"capabilities": cap,
                  "executable_path": DRIVER_BINARY_PATH,
                  "firefox_binary": FirefoxBinary(BROWSER_BINARY_PATH),
                  "options": options}

META_DATA = "meta.yml"
USER_AGENT = "headers.yml"
KATA_TYPE = ("completed", "authored", "unfinished")
KATA_LEVELS = {
    1: "indigo",
    2: "purple",
    3: "darkblue",
    4: "blue",
    5: "darkorange",
    6: "orange",
    7: "silver",
    8: "white"
}

TAB_CHAR = " " * 4


def create_list_item(href, text, level):
    badge_url = "https://img.shields.io/badge/"
    badge_header = "CodeWars"
    return f"""
    <li>
        <div>
            <a target="__blank" href="{data['codewars']['url']}/kata/{href}">
            <img src="{badge_url}{badge_header}%20-{text}-{KATA_LEVELS[level]}.svg"
            alt="{text}">
            </a>
        </div>
    </li>"""


def generate_readme(data):
    out = ""
    for v in data["user"]["kata"]:
        out += "# " + v[0].upper() + v[1:] + "\n\n"
        out += "<ul>"
        for kata in sorted(data["user"]["kata"][v], key=lambda i: i["level"]):
            out += create_list_item(**kata)
        out += "</ul>\n\n"

    with open("README.md", 'w') as readme:
        readme.write(out)


def refresh_data():
    with open(META_DATA, 'r') as d:
        data = load(d, Loader=Loader)

    for t in KATA_TYPE:
        url = data["codewars"]["url"] + "/users/" + data["user"]["name"] + "/" + t
        # html = requests.get(url, headers=headers).text

        browser = webdriver.Firefox(**BROWSER_CONFIG)
        browser.get(url)

        # Get scroll height
        last_height = browser.execute_script("return document.body.scrollHeight")

        while True:
            browser.execute_script("window.scrollTo(0, document.body.scrollHeight);")
            time.sleep(SCROLL_PAUSE_TIME)
            new_height = browser.execute_script("return document.body.scrollHeight")
            if new_height == last_height:
                break
            last_height = new_height
        html = browser.page_source
        soup = bs4.BeautifulSoup(html, 'lxml')
        data["user"]["kata"][t] = [{"href": kata.find("a").get("href").split("/")[-1],
                                    "text": re.sub(r"[^\w+]", " ", kata.find("a").text),
                                    "level": int(kata.find("span").text[0])}
                                   for kata in soup.find_all("div", attrs={"class": "item-title"})]
        browser.quit()
    with open(META_DATA, 'w') as d:
        dump(data, d, Dumper=Dumper)
    return data


def convert_to_unittest(s):
    commands = ((re.compile(r'^test(?=\.)'), "self"),
                (re.compile(r"assert_equals(?=\()"), "assertEqual"),
                (re.compile(r"assert_approx_equals(?=\()"), "assertAlmostEqual"),
                )
    for r in commands:
        s = re.sub(r[0], r[1], s)
    return re.sub(r'[^\x00-\x7F]+', ' ', s)  # removing non-ascii char


def generate_test(func_name, test_body_raw):
    test_body = "\n".join(map(lambda t: f"{TAB_CHAR * 2}" + convert_to_unittest(t.text), test_body_raw))
    return f"\n{TAB_CHAR}def test_{func_name}(self):\n{test_body}"


def generate_function_body(url):
    url = data["codewars"]["url"] + "/kata/" + url + "/train/python"
    browser = webdriver.Firefox(**BROWSER_CONFIG)
    browser.get(url)
    html = browser.page_source
    soup = bs4.BeautifulSoup(html.encode('utf-8', 'ignore'), 'lxml')

    code = soup.body.find(id="code")
    fixture = soup.body.find(id="fixture")

    func_body = "" if code is None else "\n".join(map(lambda t: t.text, code.find_all("span", role="presentation")))
    func_name = re.search(r'(?<=def ).*(?=\()', func_body)
    func = {"body": func_body,
            "name": "" if func_name is None else func_name.group(0)}

    test_body = generate_test(func["name"], fixture.find_all("span", role="presentation"))
    browser.quit()
    return func, test_body


def generate_project_files():
    with open(META_DATA, 'r') as meta:
        data = load(meta, Loader=Loader)

    for k in data["user"]["kata"]["unfinished"]:
        ext = ".py"
        file_name = re.sub(r"[^\w+]", "_", k["text"].lower())
        file_path = f"_{k['level']}kyu"
        test_path = f"test"

        test_file = test_path + "/" + test_path + file_path + ext
        source_file = file_path + "/" + file_name + ext

        if os.path.exists(file_path):
            with open(source_file, 'w') as f:
                func, test = generate_function_body(k["href"])
                f.write(func["body"])

            with open(test_file, "r+") as f:
                import_str = f"from ..{file_path}.{file_name} import {func['name']}\n"
                contents = f.readlines()
                for i, line in enumerate(contents):
                    if re.search(r"(^import unittest)", line):
                        contents.insert(i + 1, import_str)
                    if re.search(r"(^class.*:)", line):
                        contents.insert(i + 1, test)
                f.seek(0)
                f.writelines(contents)


if __name__ == "__main__":
    data = refresh_data()
    generate_readme(data)
