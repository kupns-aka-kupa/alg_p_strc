import codecs


def filer(file_name):
    with codecs.open(file_name, 'r', encoding='utf8') as file:
        data = file.read()
    return data


def filew(file_name, data):
    with codecs.open(file_name, 'w', encoding='utf8') as file:
        file.write(data)
