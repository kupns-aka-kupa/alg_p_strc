
def _matrix_multiply(m1, m2):
    if len(m1[0]) != len(m2):
        raise IndexError("Multiply matrix error: Incompatible matrix dimensions.")
    else:
        n = len(m1[0])

    m = len(m1)
    k = len(m2[0])

    result_matrix = [[0 for _ in range(k)] for _ in range(m)]

    # Matrix multiply
    for i in range(m):
        for j in range(k):
            result_matrix[j][i] = sum(m1[j][p] * m2[p][i] for p in range(n))

    return result_matrix


def _matrix_row_swap(i, k, m):
    n = len(m) - 1
    if i > n or k > n:
        raise IndexError("Impossible to change non-existent rows.")
    else:
        m[i], m[k] = m[k], m[i]
        return m


def _matrix_row_sum(i, k, m):
    n = len(m[i])
    m[i] = [m[k][j] + m[i][j] for j in range(n)]
    return m


def _matrix_row_const_multiply(i, k, m):
    return list(map(lambda j: k * j, m[i]))


def _k(i): return 1 if i % 2 == 0 else -1


def _matrix_2x2_determinant(m):
    return float(m[0][0] * m[1][1] - m[0][1] * m[1][0])


def _matrix_3x3_determinant(m):
    n = len(m[0])
    return float(sum(
        _k(i) * m[0][i] * _matrix_2x2_determinant(
            _matrix_minor(m, i)
        ) for i in range(n)
    ))


def _matrix_nxn_determinant(m):
    n = len(m[0])

    if n < 5:
        return float(sum(_k(i) * m[0][i] * _matrix_3x3_determinant(_matrix_minor(m, i)) for i in range(n)))
    else:
        return float(sum(_k(i) * m[0][i] * _matrix_nxn_determinant(_matrix_minor(m, i)) for i in range(n)))


def _matrix_minor(m, i):
    n = len(m[0])
    keys = [sorted([(i + p) % n for p in range(1, n)]) for j in range(1, n)]
    return [[m[j][keys[j - 1][p - 1]] for p in range(1, n)]
            for j in range(1, n)]


def matrix_sum(*matrices):
    m = len(matrices[0])
    n = len(matrices[0][0])
    result_matrix = [[0 for j in range(n)] for i in range(m)]

    # Matrix sum
    for matrix in matrices:
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                result_matrix[i][j] += matrix[i][j]

    return result_matrix


def matrix_const_multiply(k, m):
    n = len(m[0])
    return [_matrix_row_const_multiply(i, k, m) for i in range(n)]


def matrix_multiply_pipeline(*matrices):
    result_matrix = matrices[0]

    # Multiply pipeline
    for next_matrix in matrices[1:]:
        result_matrix = _matrix_multiply(result_matrix, next_matrix)

    return result_matrix


def matrix_determinant(m):
    n = len(m)
    if len(m) == 0:
        raise IndexError("Non matrix")
    elif n == 1:
        return m[0]

    n = len(m[0])
    if n == 2:
        return _matrix_2x2_determinant(m)
    elif n == 3:
        return _matrix_3x3_determinant(m)
    else:
        return _matrix_nxn_determinant(m)

# m = [[random.randint(-100, 100) for j in range(8)] for i in range(8)]

# D E T E R M I N A N T
# ...
# 3x3 true
# 4x4 true
# 5x5 true
# 6x6 -11863909768656 < -11863909768656.004 (numpy)
# 7x7 -852890443977641.9 < -852890443977644.9 (numpy)
# 8x8 -2.237716481496027e+16 > -2.237716481496015e+16 (numpy)
