from math import modf, ceil, e
from datetime import datetime as dt


def msrand(bottom=0, top=1, init=int(modf(dt.now().timestamp())[1])):
    size = len(bin(init))
    third = ceil(size / 3)
    init **= 2
    init >>= third
    middle = size - third * 2
    result = init % 2 ** middle

    if not(bottom == 0 and top == 1):
        return top - (result % (top - bottom + 1))

    elif bottom == 0 and top == 1:
        result_third = ceil(len(bin(result)) / 3)
        for i in range(1, result_third):
            result *= 0.1
        return e**(-result)
