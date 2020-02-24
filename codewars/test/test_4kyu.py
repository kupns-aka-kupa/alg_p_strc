import unittest
from .._4kyu.longest_slide_down import longestSlideDown
from .._4kyu.decompose_int import decompose
from .._4kyu.strip_comments import strip_comments


class Katas4TestCase(unittest.TestCase):

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
                         'pears\nwatermelons\noranges\n\nbananas avocados avocados oranges' )
        self.assertEqual(strip_comments('avocados .\n# ^ avocados\nlemons avocados',
                                        ['^', '=', ',', '!']),
                         'avocados .\n#\nlemons avocados')
        self.assertEqual(strip_comments("avocados ' avocados ,\n#\nbananas apples lemons cherries - lemons",
                                        ['=', ',', "'", '#', '!', '.', '^']),
                         'avocados\n\nbananas apples lemons cherries - lemons')


if __name__ == '__main__':
    unittest.main()
