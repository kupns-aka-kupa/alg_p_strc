from itertools import product
import math


def tribonacci(s, n):
    _l = len(s)
    if n < _l:
        return s[:n]
    for i in range(n - _l):
        s.append(sum(s[i:i + 3]))
    return s


def primes(b):
    sieve = set(range(2, b))
    for i in range(2, b + 1):
        if i in sieve:
            sieve -= set(range(2 * i, b, i))
    return sieve


def k_primes(k, a, end):
    _end = end + 1
    sieve = [0] * _end
    for i in range(2, end):
        if not sieve[i]:
            for j in range(i, _end, i):
                _j = int(j)
                while _j % i == 0:
                    _j /= i
                    sieve[j] += 1
    return [i for i in range(a, _end) if sieve[i] == k]


def k_prime_puzzle_1(s):
    _c7kp = k_primes(7, 0, s)
    if not len(_c7kp) or any(s == i for i in _c7kp):
        return 0
    count = 0
    for i in [s - i for i in _c7kp]:
        _c1kp = k_primes(1, 0, i)
        if not len(_c1kp) or any(i == j for j in _c1kp):
            continue
        _c3kp = k_primes(3, 0, i)
        if not len(_c3kp) or any(i == j for j in _c3kp):
            continue
        for _1kp in _c1kp:
            for _3kp in _c3kp:
                if _1kp + _3kp is i:
                    count += 1
    return count


def k_prime_puzzle_2(s):
    _c7kp = k_primes(7, 0, s)
    if not len(_c7kp) or any(s == i for i in _c7kp):
        return 0
    count = 0
    for i in [s - i for i in _c7kp]:
        _c1kp = k_primes(1, 0, i)
        if not len(_c1kp) or any(i == j for j in _c1kp):
            continue
        _c3kp = k_primes(3, 0, i)
        if not len(_c3kp) or any(i == j for j in _c3kp):
            continue
        for _1kp in _c1kp:
            for _3kp in _c3kp:
                if _1kp + _3kp is i:
                    count += 1
    return count


def ulam_seq(u0, u1, n):
    res = [u0, u1]
    for i in range(n - len(res)):
        res.append(set(res))
    return res


def super_sum(d, n):
    return d * n ** d * (n - 1) // 2


def max_sequence(arr):
    if not len(arr) or all(i <= 0 for i in arr):
        return [[], 0]
    _r, _l = [0], [0]
    _sub_arr_i = 0
    _s = _max = 0
    for i in range(len(arr)):
        _s += arr[i]
        _i = i + 1
        if _s < 0:
            _s = 0
            _r.append(0)
            _l.append(0)
            _sub_arr_i += 1
            _r[_sub_arr_i] = _i
        elif _max < _s:
            _max = _s
            _l[_sub_arr_i] = _i
    if _l[_sub_arr_i] == 0:
        _l[_sub_arr_i] = len(arr)
    _subarr = [arr[_r[i]:_l[i]] for i in range(_sub_arr_i + 1)
               if sum(arr[_r[i]:_l[i]]) == _max]
    if len(_subarr) == 1:
        return [_subarr[0], _max]
    return [_subarr, _max]
