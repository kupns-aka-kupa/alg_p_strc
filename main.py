from random import randint

from algorithms.random import msrand
from algorithms.search import linse, reclinse, binse
from algorithms.sort import chanso, bubso, mersow, inso
from algorithms.pnum import erat_sieve, html_table_gen, atkin_sieve, true_div
from algorithms.output import filew

if __name__ == "__main__":
    lenght = input('Enter massive lenght:',)
    mass = [randint(1, 1000) for i in range(int(lenght))]
    print('Random mass:', mass)
    sort = mersow(mass)
    print('Sorted mass:', sort)
    search = linse(sorted(mass), input('Enter value:',))
    print('Search:', search)
    print('Random:', msrand(1, 1000))
    print('Delimeters of', 1000, ':', true_div(1000))
    filew('output/atkinSieve.html', html_table_gen(atkin_sieve(1000)))
    filew('output/eratSieve.html', html_table_gen(erat_sieve(1000)))
