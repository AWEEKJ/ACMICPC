"""
Merge Sort
- Time Complexity is O(nlogn).
- Space Complexity is O(n).
"""


def merge(arr_a, arr_b):
    result = []
    i = j = 0
    while i < len(arr_a) and j < len(arr_b):
        if arr_a[i] <= arr_b[j]:
            result.append(arr_a[i])
            i += 1
        else:
            result.append(arr_b[j])
            j += 1
    if arr_a[i:]:
        result.extend(arr_a[i:])
    if arr_b[j:]:
        result.extend(arr_b[j:])
    return result


def merge_sort(arr):
    n = len(arr)
    if n <= 1: 
        return arr
    else:
        a1 = merge_sort(arr[:n//2])
        a2 = merge_sort(arr[n//2:])
    return merge(a1, a2)
        
if __name__ == '__main__':
    test = [5, 13, 2, 25, 7, 17, 20, 8, 4]
    print(merge_sort(test))
