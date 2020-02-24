import re


def strip_comments(s, m):
    if len(m) > 0:
        pattern = '\\'.join(m)
        return re.sub(rf'[ ]*[\{pattern}].*', '', s)
    else:
        return s
