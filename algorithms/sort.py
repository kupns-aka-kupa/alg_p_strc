def bubble_sort(m):
    """ Bubble sort impl O(n^2)
    @param m: sort collection
    @return sorted(@m)
    """
    for i in range(len(m) - 1):
        for j in range(len(m) - i - 1):
            if m[j] > m[j + 1]:
                m[j], m[j + 1] = m[j + 1], m[j]
    return m


def insert_sort(m):
    for i in range(len(m)):
        key = m[i]
        j = i - 1
        while j >= 0 and key < m[j]:
            m[j + 1] = m[j]
            j -= 1
        m[j + 1] = key
    return m


def change_sort(m):
    for i in range(len(m)):
        _min = i
        for j in range(i + 1, len(m)):
            if m[j] < m[_min]:
                _min = j
        if _min != i:
            m[i], m[_min] = m[_min], m[i]
    return m


import random
def quick_sort(m):
    """ Quick sort impl O(log n)
    @param m: sort collection
    @return sorted(@m)
    """
    if len(m) < 1:
        return m
    b = random.choice(m)  # break point

    l = [i for i in m if i < b]
    e = [b] * m.count(b)
    r = [i for i in m if i > b]

    return quick_sort(l) + e + quick_sort(r)


def merge_sort(m):
    """ Merge sort impl O(log n)
    @param m: sort collection
    @return sorted(@m)
    """
    _len = len(m)
    if _len <= 1:
        return m
    mid = _len // 2
    l = merge_sort(m[:mid])
    r = merge_sort(m[mid:])
    return merge(l, r)


def merge(l, r):
    """ Merge sort helper
    @type l: list
    @type r: list
    """
    merged = []

    while len(l) and len(r):
        if l[0] <= r[0]:
            merged.append(l[0])
            l.pop(0)
        else:
            merged.append(r[0])
            r.pop(0)

    return merged + l + r

