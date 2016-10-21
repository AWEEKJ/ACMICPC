"""
Heap Sort
Time Complexity: O(nlogn)
Space Complexity: O(1)
"""

def max_heapify(A, index, heap_size):
    l = 2 * index + 1
    r = 2 * index + 2
    if l <= heap_size and A[l] > A[index]:
        largest = l
    else:
        largest = index
    if r <= heap_size and A[r] > A[largest]:
        largest = r
    if largest != index:
        A[largest], A[index] = A[index], A[largest]
        max_heapify(A, largest, heap_size)

def build_max_heap(A):
    heap_size = len(A) - 1
    for i in range((len(A)-2)//2, -1, -1):
        max_heapify(A, i, heap_size)

def heap_sort(A):
    build_max_heap(A)
    heap_size = len(A) - 1
    for i in range(heap_size, 0, -1):
        A[0], A[i] = A[i], A[0]
        heap_size = heap_size - 1
        max_heapify(A, 0, heap_size)
    return A

if __name__ == '__main__':
    list = [5, 13, 2, 25, 7, 17, 20, 8, 4]
    heap_sort(list)
    print(list)
