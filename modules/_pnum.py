from math import floor


def tblgen(mass):
    str_res = ''
    table = {
        'tbs': '<table border="1">',
        'trs': '<tr>',
        'tds': '<td><p>',
        'tde': '</p></td>',
        'tre': '</tr>',
        'tbe': '</table>'
    }

    str_res += table['tbs']
    s = 10
    i = 0
    while i < len(mass):
        str_res += table['trs']
        j = 0
        while j < 10:
            try:
                str_res += table['tds'] + str(mass[j + i]) + table['tde']
                j += 1
            except IndexError:
                break

        str_res += table['tre']
        i += s
    str_res += table['tbe']
    return str_res


def ersieve(n=10):
    trash = [2]
    res = [2]
    for i in range(3, n):
        trash.append(i)
        exep = False
        for j in trash:
            if i % j == 0:
                if i != j:
                    exep = True
                break
        if exep:
            continue
        else:
            res.append(i)
    return res


def atksieve(n=10):
    sq = floor(n ** (1 / 2))
    res = [False for i in range(n)]
    res[2] = True
    res[3] = True

    for i in range(sq):
        for j in range(sq):

            fx = 4 * i ** 2 + j ** 2
            if (fx % 12 == 1 or fx % 12 == 5) and fx <= n:
                res[fx] = not res[fx]

            fx = 3 * i ** 2 + j ** 2
            if fx % 12 == 7 and fx <= n:
                res[fx] = not res[fx]

            fx = 3 * i ** 2 - j ** 2
            if n % 12 == 11 and fx <= n and i > j:
                res[fx] = not res[fx]

    for i in range(5, sq):
        if res[i]:
            fx = i ** 2
            for j in range(fx, sq, fx):
                res[j - 1] = False

    return [i for i in range(len(res)) if res[i]]


def trdiv(n):
    a = []
    f = 2
    while n > 1:
        if n % f == 0:
            a.append(f)
            n /= f
        else:
            f += 1
    return a
