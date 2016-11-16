import unittest
import random

from bubble_sort import bubble_sort
from heap_sort import heap_sort
from insertion_sort import insertion_sort
from merge_sort import merge_sort
from randomized_quick_sort import randomized_quick_sort
from quick_sort import quick_sort


class TestSort(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        unittest.TestCase.__init__(self, *args, **kwargs)
        self.arr = random.sample(list(range(100)), 20)  # Create random list for test
        self.answer = sorted(self.arr)                  # Sort the random list

    def test_bubble_sort(self):
        result = bubble_sort(self.arr)
        self.assertEqual(result, self.answer)

    def test_heap_sort(self):
        result = heap_sort(self.arr)
        self.assertEqual(result, self.answer)

    def test_insertion_sort(self):
        result = insertion_sort(self.arr)
        self.assertEqual(result, self.answer)

    def test_merge_sort(self):
        result = merge_sort(self.arr)
        self.assertEqual(result, self.answer)

    def test_randomized_quick_sort(self):
        result = randomized_quick_sort(self.arr)
        self.assertEqual(result, self.answer)

    def test_quick_sort(self):
        result = quick_sort(self.arr)
        self.assertEqual(result, self.answer)

if __name__ == '__main__':
    unittest.main()
