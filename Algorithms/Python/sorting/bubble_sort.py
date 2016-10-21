"""
Bubble Sort
Time Complexity: O(n^2)
Space Complexity: O(1)
"""

def bubble_sort(A):
    n = len(A)
    num_swaps = 0
    for i in range(0, n):
        for j in range(0, n-1):
            if A[j] > A[j+1]:
                A[j], A[j+1] = A[j+1], A[j]
                num_swaps += 1;
        if num_swaps == 0:
            break;


if __name__ == '__main__':
    list = [5, 13, 2, 25, 7, 17, 20, 8, 4]
    bubble_sort(list)
    print(list)
