"""
Bubble Sort
- Time Complexity is O(n^2).
- Space Complexity is O(1).
"""


def bubble_sort(arr):
    n = len(arr)-1
    for i in range(n):
        for j in range(n-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


if __name__ == '__main__':
    test = [5, 13, 2, 25, 7, 17, 20, 8, 4]
    bubble_sort(test)
    print(test)
