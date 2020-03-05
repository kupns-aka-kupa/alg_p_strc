from datetime import datetime as dt


def timeit(method):
    def wrapper(arg):
        start = dt.now()
#       print('Unsorted list:' + str(arg))
        result = method(arg)
        print('Time has taken: ' + str(dt.now()-start))# + '\nSorted list: ' + str(result))
        return result
    return wrapper
