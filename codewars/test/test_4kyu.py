import unittest
from .._4kyu.longest_slide_down import longestSlideDown
from .._4kyu.decompose_int import decompose
from .._4kyu.strip_comments import strip_comments
from .._4kyu.rectangle_rotation import rectangle_rotation
from .._4kyu.ranking_system import User
from .._4kyu.matrix_determinant import determinant
from .._4kyu.permutations import permutations


class Katas4TestCase(unittest.TestCase):
    def test_permutations(self):
        self.assertEqual(sorted(permutations('a')), ['a'])
        self.assertEqual(sorted(permutations('ab')), ['ab', 'ba'])
        self.assertEqual(sorted(permutations('aabb')), ['aabb', 'abab', 'abba', 'baab', 'baba', 'bbaa'])

    def test_determinant(self):
        m1 = [[1, 3], [2, 5]]
        m2 = [[2, 5, 3], [1, -2, -1], [1, 3, 4]]
        self.assertEqual(determinant([[1]]), 1)
        self.assertEqual(determinant(m1), -1)
        self.assertEqual(determinant(m2), -20)

    def test_rectangle_rotation(self):
        self.assertEqual(rectangle_rotation(6, 4), 23)
        self.assertEqual(rectangle_rotation(30, 2), 65)
        self.assertEqual(rectangle_rotation(8, 6), 49)
        self.assertEqual(rectangle_rotation(16, 20), 333)

    def test_ranking_system(self):
        user = User()
        self.assertEqual(user.progress, 0)
        user.inc_progress(7)
        user.inc_progress(4)
        user.inc_progress(8)
        user.inc_progress(-5)

    def test_longest_slide_down(self):
        self.assertEqual(longestSlideDown([[3], [7, 4], [2, 4, 6], [8, 5, 9, 3]]), 23)

    def test_decompose_int(self):
        self.assertEqual(decompose(11), [1, 2, 4, 10])
        self.assertEqual(decompose(50), [1, 3, 5, 8, 49])

    def test_strip_comments(self):
        self.assertEqual(strip_comments("apples, pears # and bananas\ngrapes\nbananas !apples", ["#", "!"]),
                         "apples, pears\ngrapes\nbananas")
        self.assertEqual(strip_comments("a #b\nc\nd $e f g", ["#", "$"]), "a\nc\nd")
        self.assertEqual(strip_comments("#", ["#", "!"]), "")
        self.assertEqual(strip_comments('\n§', ['#', '§']), "\n")
        self.assertEqual(strip_comments('pears - @\nwatermelons . avocados avocados watermelons\noranges\n@ '
                                        'watermelons lemons oranges\nbananas avocados avocados oranges', ['^', '=',
                                                                                                          '@', '-',
                                                                                                          "'", ',',
                                                                                                          '.', '#']),
                         'pears\nwatermelons\noranges\n\nbananas avocados avocados oranges')
        self.assertEqual(strip_comments('avocados .\n# ^ avocados\nlemons avocados',
                                        ['^', '=', ',', '!']),
                         'avocados .\n#\nlemons avocados')
        self.assertEqual(strip_comments("avocados ' avocados ,\n#\nbananas apples lemons cherries - lemons",
                                        ['=', ',', "'", '#', '!', '.', '^']),
                         'avocados\n\nbananas apples lemons cherries - lemons')


if __name__ == '__main__':
    unittest.main()
