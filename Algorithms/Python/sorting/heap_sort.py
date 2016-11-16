"""
Heap Sort
- Time Complexity is O(nlogn).
- Space Complexity is O(1).
"""


def max_heapify(arr, index, heap_size):
    l = 2 * index + 1
    r = 2 * index + 2
    if l <= heap_size and arr[l] > arr[index]:
        largest = l
    else:
        largest = index
    if r <= heap_size and arr[r] > arr[largest]:
        largest = r
    if largest != index:
        arr[largest], arr[index] = arr[index], arr[largest]
        max_heapify(arr, largest, heap_size)


def build_max_heap(arr):
    heap_size = len(arr) - 1
    for i in range((len(arr)-2)//2, -1, -1):
        max_heapify(arr, i, heap_size)


def heap_sort(arr):
    build_max_heap(arr)
    heap_size = len(arr) - 1
    for i in range(heap_size, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heap_size -= 1
        max_heapify(arr, 0, heap_size)
    return arr


if __name__ == '__main__':
    test = [5, 13, 2, 25, 7, 17, 20, 8, 4]
    heap_sort(test)
    print(test)
