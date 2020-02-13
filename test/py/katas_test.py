from katas import *
import unittest


class KatasTestCase(unittest.TestCase):

    def test_super_max_seq(self):
        self.assertEqual(max_sequence([-2, 1, -3, 4, -1, 2, 1, -5, 4]), [[4, -1, 2, 1], 6])
        self.assertEqual(max_sequence([4, -1, 2, 1, -40, 1, 2, -1, 4]), [[[4, -1, 2, 1], [1, 2, -1, 4]], 6])
        self.assertEqual(max_sequence([-2, 1, 4, -1, 2, 1, -5, 4]), [[1, 4, -1, 2, 1], 7])
        self.assertEqual(max_sequence([-2, -1, 2, 1, -5, 4]), [[4], 4])
        self.assertEqual(max_sequence([2, 1, 2, 1]), [[2, 1, 2, 1], 6])
        self.assertEqual(max_sequence([-2, -1, -2, -1]), [[], 0])
        self.assertEqual(max_sequence([]), [[], 0])

    def test_super_sum(self):
        self.assertEqual(super_sum(1, 1), 0)
        self.assertEqual(super_sum(1, 10), 45)
        self.assertEqual(super_sum(2, 2), 4)
        self.assertEqual(super_sum(2, 3), 18)
        self.assertEqual(super_sum(2, 10), 900)
        self.assertEqual(super_sum(3, 3), 81)
        self.assertEqual(super_sum(4, 4), 1536)
        self.assertEqual(super_sum(5, 5), 31250)
        self.assertEqual(super_sum(6, 6), 699840)
        self.assertEqual(super_sum(7, 7), 17294403)
        self.assertEqual(super_sum(8, 8), 469762048)

    def test_k_number(self):
        self.assertEqual(k_primes(5, 500, 600), [500, 520, 552, 567, 588, 592, 594])
        self.assertEqual(k_primes(2, 0, 100),
                         [4, 6, 9, 10, 14, 15, 21, 22, 25, 26, 33, 34, 35, 38, 39, 46, 49, 51, 55, 57, 58, 62, 65, 69,
                          74, 77, 82, 85,
                          86, 87, 91, 93, 94, 95])
        self.assertEqual(k_primes(2, 0, 100), [4, 6, 9, 10, 14, 15, 21, 22, 25, 26, 33, 34, 35, 38, 39, 46, 49, 51, 55,
                                               57, 58, 62, 65, 69, 74, 77, 82, 85, 86, 87, 91, 93, 94, 95])

    def test_kpuzzle(self):
        self.assertEqual(k_prime_puzzle_1(138), 1)
        self.assertEqual(k_prime_puzzle_1(143), 2)
        self.assertEqual(k_prime_puzzle_1(10253), 73)


if __name__ == '__main__':
    unittest.main()
