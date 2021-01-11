from math import modf, e
from datetime import datetime as dt


def rand(bottom=0, top=1, init=int(modf(dt.now().timestamp())[1])):
    size = len(bin(init))
    third = size // 3
    init **= 2
    init >>= third
    middle = size - third * 2
    result = init % 2 ** middle

    return top - (result % (top - bottom + 1))
        result *= 0.1
    return e**(-result)
