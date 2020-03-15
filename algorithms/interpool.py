def binomial(n, k):
    """
    Args:
       n: 
       k: 

    Returns:
        Binomial coefficient / n \
                             \k /
    """
    return factorial(1, n) // (factorial(1, k) * factorial(1, n - k))


def factorial(f, n):
    """ f = n! , if n = 0 or 1 f = 1 """
    return factorial(f * n, n - 1) if n > 1 else f


def basis(n, k, t):
    """ Bernstein basis polynomials """
    if t == 0 and k == 0:
        ti = 1
    else:
        ti = pow(t, k)

    if n == k and t == 1:
        tni = 1
    else:
        tni = pow(1 - t, n - k)

    return binomial(n, k) * ti * tni


def polynomial(x, a, *args):
    fx = a
    for i in range(len(args)):
        fx = fx + pow(x, i) * args[i]
    return fx


def linear(points, divisions):
    N = len(points)
    a, b = [], []
    inPoints = []

    for k in range(1, N):
        a[k] = (points[k][2] - points[k - 1][2]) / (points[k][1] - points[k - 1][1])
        b[k] = points[k][2] - a[k] * points[k][1]

    for k in range(1, N):
        stpx = points[k - 1][1]
        px = points[k][1]
        dx = (px - stpx) / divisions

        for s in range(stpx, px, dx):
            Fy = polynomial(s, b[k], a[k])
            inPoints.append([s, Fy])

    return inPoints


def bezier(points, depth):
    inPoints, icount, t, step = {}, 1, 0, 1 / depth

    N = len(points) - 1
    for i1 in range(depth):
        if 1 - t < 0.000001: t = 1

        inPoints[icount], jcount = {0, 0}, 1

        for i in range(N):
            b = basis(N, i, t)
            inPoints[icount] = [
                inPoints[icount][1] + b * points[jcount][1],
                inPoints[icount][2] + b * points[jcount][2]]
            jcount = jcount + 1

        t, icount = t + step, icount + 1

    return inPoints


def spline(points, divisions):
    N = len(points)
    h, l, delta, lam, c, d, b = {}, {}, {}, {}, {}, {}, {}

    for k in range(1, N):
        h[k] = points[k][1] - points[k - 1][1]
        if h[k] == 0:
            return points

        l[k] = (points[k][2] - points[k - 1][2]) / h[k]

    delta[2] = -h[3] / (2 * (h[2] + h[3]))
    lam[2] = 1.5 * (l[3] - l[2]) / (h[2] + h[3])

    for k in range(3, N):
        delta[k - 1] = - h[k] / (2 * h[k - 1] + 2 * h[k] + h[k - 1] * delta[k - 2])
        lam[k - 1] = (3 * (l[k] - l[k - 1]) - h[k - 1] * lam[k - 2]) / (2 * (h[k - 1] + h[k]) + h[k - 1] * delta[k - 2])

    c[1], c[N] = 0, 0
    for k in range(N, 3, -1):
        c[k - 1] = delta[k - 1] * c[k] + lam[k - 1]

    for k in range(1, N):
        d[k] = (c[k] - c[k - 1]) / (3 * h[k])
        b[k] = l[k] + (2 * c[k] * h[k] + h[k] * c[k - 1]) / 3

    return calcPoints(points, divisions, b, c, d)


def calcPoints(points, divisions, *args):
    N = len(points)
    inPoints = {}

    for k in range(1, N):
        stpx = points[k - 1][1]
        px = points[k][1]
        dx = (px - stpx) / divisions
        for s in range(stpx, px, dx):
            if points[k - 1][1] <= s <= points[k][1]:
                fx = polynomial(s - points[k][1], points[k][2], args[1][k], args[2][k], args[3][k])
                inPoints.append([s, fx])
    return inPoints
