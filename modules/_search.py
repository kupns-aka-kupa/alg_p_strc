from math import floor


def linse(mass, value):
    for i in mass:
        if i == value:
            return i


def reclinse(mass, value, i):
    if i > len(mass):
        return None
    elif i == value:
        return i
    else:
        reclinse(i + 1)


def binse(mass, value):
    i = 0
    k = len(mass)
    while i <= k:
        i = floor(k / 2)
        if mass[i] == value:
            return i + 1
        elif mass[i] < value:
            k += i - 1
        elif mass[i] > value:
            k -= i
    else:
        return None
