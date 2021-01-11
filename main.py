from random import randint

from algorithms.search import linear_search, bin_search
from algorithms.sort import change_sort, bubble_sort, merge_sort, insert_sort, quick_sort

if __name__ == "__main__":
    lenght = 20
    mass = [randint(1, 1000) for i in range(int(lenght))]
    print('Random mass:', mass)
    sort = merge_sort(mass)
    print('Sorted mass:', sort)
    while True:
        search = bin_search(sorted(mass), int(input('Enter value:',)))
        print('Search:', list(search))
