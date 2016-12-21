"""
Insertion Sort
- Best Time Complexity is O(n) when array is already sorted.
- Worst Time Complexity is O(n^2).
- Space Complexity is O(1).
"""


def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        for j in range(i, 0, -1):
            if arr[j] < arr[j-1]:
                arr[j], arr[j-1] = arr[j-1], arr[j]
            else:
                break
    return arr


if __name__ == '__main__':
    test = [5, 13, 2, 25, 7, 17, 20, 8, 4]
    insertion_sort(test)
    print(test)
