from math import floor



def atkin_sieve(n=10):
    sq = floor(n ** (1 / 2))
    res = [False for i in range(n)]
    res[2] = True
    res[3] = True

    for i in range(sq):
        for j in range(sq):

            fx = 4 * i ** 2 + j ** 2
            o = fx % 12
            if (o == 1 or o == 5) and fx <= n:
                res[fx] = not res[fx]

            fx = 3 * i ** 2 + j ** 2
            o = fx % 12
            if o == 7 and fx <= n:
                res[fx] = not res[fx]

            fx = 3 * i ** 2 - j ** 2
            o = fx % 12
            if o % 12 == 11 and fx <= n and i > j:
                res[fx] = not res[fx]

    for i in range(5, sq):
        if res[i]:
            fx = i ** 2
            for j in range(fx, sq, fx):
                res[j - 1] = False

    return [i for i in range(len(res)) if res[i]]


def true_div(n):
    """
    @param n: number
    @type n: int
    @return list of delimiters
    """
    a = []
    f = 2
    while n > 1:
        if n % f == 0:
            a.append(f)
            n /= f
        else:
            f += 1
    return a
