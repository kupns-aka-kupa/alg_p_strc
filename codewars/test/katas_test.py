from .._6kyu.super_coords_sum import super_sum
from .._6kyu.ulam_seq import ulam_seq
from .._5kyu.max_sub_array_sum import max_sequence
from .._5kyu.kprimes import *
from .._5kyu.simple_pig import pig_it
from .._5kyu.number_factorization import primeFactors
from .._4kyu.longest_slide_down import longestSlideDown
from .._4kyu.decompose_int import decompose
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

    def test_ulam_seq(self):
        self.assertEqual(ulam_seq(1, 2, 5), [1, 2, 3, 4, 6])
        self.assertEqual(ulam_seq(1, 2, 5), [1, 2, 3, 4, 6])
        self.assertEqual(ulam_seq(3, 4, 5), [3, 4, 7, 10, 11])
        self.assertEqual(ulam_seq(5, 6, 8), [5, 6, 11, 16, 17, 21, 23, 26])
        self.assertEqual(ulam_seq(3, 4, 5), [3, 4, 7, 10, 11])
        a = [1, 2, 3, 4, 6, 8, 11, 13, 16, 18, 26, 28, 36, 38, 47, 48, 53, 57, 62, 69]
        self.assertEqual(ulam_seq(1, 2, 20), a)
        a = [1, 3, 4, 5, 6, 8, 10, 12, 17, 21, 23, 28, 32, 34, 39, 43, 48, 52, 54, 59, 63, 68, 72, 74, 79, 83, 98, 99,
             101, 110, 114, 121, 125, 132, 136, 139, 143, 145, 152, 161, 165, 172, 176, 187, 192, 196, 201, 205, 212,
             216, 223, 227, 232, 234, 236, 243, 247, 252, 256, 258]
        self.assertEqual(ulam_seq(1, 3, 60), a)

    def test_k_number(self):
        self.assertEqual(count_Kprimes(5, 500, 600), [500, 520, 552, 567, 588, 592, 594])
        self.assertEqual(count_Kprimes(2, 0, 100),
                         [4, 6, 9, 10, 14, 15, 21, 22, 25, 26, 33, 34, 35, 38, 39, 46, 49, 51, 55, 57, 58, 62, 65, 69,
                          74, 77, 82, 85, 86, 87, 91, 93, 94, 95])
        self.assertEqual(count_Kprimes(2, 0, 100),
                         [4, 6, 9, 10, 14, 15, 21, 22, 25, 26, 33, 34, 35, 38, 39, 46, 49, 51, 55,
                          57, 58, 62, 65, 69, 74, 77, 82, 85, 86, 87, 91, 93, 94, 95])
        self.assertEqual(count_Kprimes(5, 1000, 1100), [1020, 1026, 1032, 1044, 1050, 1053, 1064, 1072, 1092, 1100])
        self.assertEqual(count_Kprimes(5, 500, 600), [500, 520, 552, 567, 588, 592, 594])
        self.assertEqual(count_Kprimes(4, 2668458, 2668805),
                         [2668458, 2668468, 2668482, 2668485, 2668493, 2668494, 2668497,
                          2668504, 2668509, 2668515, 2668522, 2668525, 2668526, 2668530,
                          2668532, 2668533, 2668534, 2668542, 2668548, 2668551, 2668556,
                          2668562, 2668566, 2668567, 2668570, 2668578, 2668589, 2668599,
                          2668604, 2668611, 2668612, 2668614, 2668617, 2668622, 2668623,
                          2668628, 2668636, 2668645, 2668648, 2668665, 2668668, 2668674,
                          2668676, 2668686, 2668687, 2668689, 2668694, 2668699, 2668708,
                          2668712, 2668721, 2668722, 2668730, 2668731, 2668748, 2668756,
                          2668759, 2668762, 2668772, 2668779, 2668780, 2668790, 2668794,
                          2668797, 2668804, 2668805])
        self.assertEqual(count_Kprimes(3, 1019275, 1019722),
                         [1019275, 1019289, 1019290, 1019293, 1019301, 1019302, 1019303, 1019305, 1019308, 1019311,
                          1019314, 1019317, 1019319, 1019324, 1019332, 1019333, 1019334, 1019335, 1019338, 1019346,
                          1019355, 1019361, 1019366, 1019369, 1019371, 1019379, 1019389, 1019390, 1019391, 1019395,
                          1019401, 1019409, 1019414, 1019415, 1019417, 1019422, 1019427, 1019428, 1019429, 1019434,
                          1019435, 1019438, 1019447, 1019454, 1019455, 1019461, 1019465, 1019469, 1019476, 1019477,
                          1019478, 1019489, 1019492, 1019499, 1019505, 1019506, 1019511, 1019514, 1019515, 1019516,
                          1019518, 1019521, 1019522, 1019541, 1019542, 1019543, 1019548, 1019553, 1019557, 1019567,
                          1019570, 1019573, 1019579, 1019582, 1019583, 1019585, 1019596, 1019597, 1019598, 1019599,
                          1019603, 1019607, 1019609, 1019614, 1019615, 1019618, 1019621, 1019622, 1019626, 1019629,
                          1019630, 1019631, 1019635, 1019638, 1019641, 1019642, 1019643, 1019644, 1019645, 1019649,
                          1019654, 1019658, 1019659, 1019665, 1019669, 1019675, 1019678, 1019679, 1019685, 1019695,
                          1019698, 1019703, 1019705, 1019706, 1019708, 1019714, 1019716, 1019722])

    def test_kpuzzle(self):
        self.assertEqual(puzzle(138), 1)
        self.assertEqual(puzzle(143), 2)
        self.assertEqual(puzzle(1025), 393)

    def test_simple_pig(self):
        self.assertEqual(pig_it('Pig latin is cool'), "igPay atinlay siay oolcay")
        self.assertEqual(pig_it('Hello world !'), "elloHay orldway !")
        self.assertEqual(pig_it('This is my string'), 'hisTay siay ymay tringsay')

    def test_num_factorization(self):
        self.assertEqual(primeFactors(7775460), "(2**2)(3**3)(5)(7)(11**2)(17)")

    def test_longest_slide_down(self):
        self.assertEqual(longestSlideDown([[3], [7, 4], [2, 4, 6], [8, 5, 9, 3]]), 23)

    def test_decompose_int(self):
        self.assertEqual(decompose(11), [1, 2, 4, 10])
        self.assertEqual(decompose(50), [1, 3, 5, 8, 49])


if __name__ == '__main__':
    unittest.main()
