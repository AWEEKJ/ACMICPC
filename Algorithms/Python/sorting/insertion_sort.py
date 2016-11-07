"""
Insertion Sort
Time Complexity: O(n^2)
Space Complexity: O(1)
"""

def insertion_sort(A):
    n = len(A)
    for i in range(1, n):
        for j in range(i, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]


if __name__ == '__main__':
    list = [5, 13, 2, 25, 7, 17, 20, 8, 4]
    insertion_sort(list)
    print(list)
