import math
from modules._decor import timeit


@timeit
def bubso(mass):
    for j in range(0, len(mass) - 1):
        for i in range(0, len(mass) - 1):
            if mass[i] > mass[i + 1]:
                mass[i], mass[i + 1] = mass[i + 1], mass[i]
                # or
                # tmp = mass[i]
                # mass[i] = mass[i + 1]
                # mass[i + 1] = tmp
    return mass


@timeit
def inso(mass):
    for i in range(len(mass)):
        key = mass[i]
        j = i - 1
        while j >= 0 and key < mass[j]:
            mass[j + 1] = mass[j]
            j -= 1
        mass[j + 1] = key
    return mass


@timeit
def chanso(mass):
    for i in range(len(mass)):
        _min = i
        for j in range(i + 1, len(mass)):
            if mass[j] < mass[_min]:
                _min = j
        if _min != i:
            mass[i], mass[_min] = mass[_min], mass[i]
    return mass


@timeit
def mersow(mass):
    def merge_sort(mass):
        if len(mass) <= 1:
            return mass
        else:
            mid = math.floor(len(mass) / 2)
            r = merge_sort(mass[: mid])
            l = merge_sort(mass[mid:])
            return merge(r, l)

    def merge(r, l):
        merged = []
        while len(r) > 0 and len(l) > 0:
            if r[0] <= l[0]:
                merged.append(r[0])
                r.pop(0)
                # or
                # r = r[1:]
            else:
                merged.append(l[0])
                l.pop(0)
        if len(r) > 0:
            merged += r
        elif len(l) > 0:
            merged += l
        return merged

    return merge_sort(mass)
