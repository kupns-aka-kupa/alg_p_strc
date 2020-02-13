from random import randint

from modules._random import msrand
from modules._search import linse, reclinse, binse
from modules._sort import chanso, bubso, mersow, inso
from modules._pnum import ersieve, tblgen, atksieve, trdiv
from modules._output import filew

if __name__ == "__main__":
    lenght = input('Enter massive lenght:',)
    mass = [randint(1, 1000) for i in range(int(lenght))]
    print('Random mass:', mass)
    sort = mersow(mass)
    search = linse(sorted(mass), input('Enter value:',))
    print('Search:', search)
    print('Random:', msrand(1, 1000))
    print('Sorted mass:', sort)
    print('Delimeters of', 1000, ':', trdiv(1000))
    filew('output/atkinSieve.html', tblgen(atksieve(1000)))
    filew('output/eratSieve.html', tblgen(ersieve(1000)))
