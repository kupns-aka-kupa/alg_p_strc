
def generate_list_item(href, text, level):
    badge_url = "https://img.shields.io/badge/"
    badge_header = "CodeWars"
    return f"""
    <li>
        <div>
            <a target="__blank" href="{data['codewars']['url']}/kata/{href}">
            <img src="{badge_url}{badge_header}%20-{text}-{KATA_LEVELS[level]}.svg" alt="{text}">
            </a>
        </div>
    </li>"""


def generate_html_list(data):
    out = "<ul>"
    for kata in data:
        out += generate_list_item(**kata)
    out += "</ul>\n\n"


def generate_readme(data):
    out = ""
    for v in data["user"]["kata"]:
        out += "# " + v[0].upper() + v[1:] + "\n\n"
        generate_html_list(sorted(data["user"]["kata"][v], key=lambda i: i["level"]))

    with open("README.md", 'w') as readme:
        readme.write(out)


def generate_html_table(mass, size=10, style='border="1"'):
    str_res = f'<table {style}>'
    rows = [mass[i:i + size] for i in range(0, len(mass), size)]
    str_res += "".join(['<tr>' + "".join(map(lambda x: '<td><p>' + str(x) + '</p></td>', i)) + '</tr>' for i in rows])
    str_res += '</table>'
    return str_res
