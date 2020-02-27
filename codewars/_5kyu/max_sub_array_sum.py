
def find_subarr_maxsum(arr):
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
