import unittest
from .._3kyu.binomial_expansion import expand
from .._3kyu.million_fibonacci import fib


class Kata3TestCase(unittest.TestCase):
    def test_millionth_fibonacci(self):
        self.assertEqual(fib(0), 0)
        self.assertEqual(fib(1), 1)
        self.assertEqual(fib(2), 1)
        self.assertEqual(fib(3), 2)
        self.assertEqual(fib(4), 3)
        self.assertEqual(fib(5), 5)
        self.assertEqual(fib(1000),
                         43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875)

    def test_binomial_expansion(self):
        self.assertEqual(expand("(-c-11)^1"), '-c-11')
        self.assertEqual(expand("(-q-8)^3"), '-q^3-24q^2-192q-512')
        self.assertEqual(expand("(-h-16)^3"), "h^3-48h^2-768h-4096")
        self.assertEqual(expand("(-k-13)^3"), "-k^3-39k^2-507k-2197")
        self.assertEqual(expand("(x+1)^0"), "1")
        self.assertEqual(expand("(x+1)^1"), "x+1")
        self.assertEqual(expand("(x+1)^2"), "x^2+2x+1")
        self.assertEqual(expand("(x-1)^0"), "1")
        self.assertEqual(expand("(x-1)^1"), "x-1")
        self.assertEqual(expand("(x-1)^2"), "x^2-2x+1")
        self.assertEqual(expand("(5m+3)^4"), "625m^4+1500m^3+1350m^2+540m+81")
        self.assertEqual(expand("(2x-3)^3"), "8x^3-36x^2+54x-27")
        self.assertEqual(expand("(7x-7)^0"), "1")
        self.assertEqual(expand("(-5m+3)^4"), "625m^4-1500m^3+1350m^2-540m+81")
        self.assertEqual(expand("(-2k-3)^3"), "-8k^3-36k^2-54k-27")
        self.assertEqual(expand("(-7x-7)^0"), "1")


if __name__ == '__main__':
    unittest.main()
