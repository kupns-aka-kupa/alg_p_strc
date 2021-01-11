

def linear_search(m, v):
    """ Binary search impl
    @param m: search collection
    @param v: searching value
    @type m: object
    @type v: object
    @return index of @v in @m
    """
    for i in range(len(m)):
        if m[i] == v:
            yield i


def bin_search(m, v):
    """ Binary search impl
    @param m: search collection
    @param v: searching value
    @type m: object
    @type v: object
    @return index of @v in @m
    """
    l = 0
    h = len(m) - 1
    while l <= h:
        i = (l + h) >> 1
        if m[i] > v:
            h = i - 1
        elif m[i] < v:
            l = i + 1
        else:
            yield i
            l += 1
