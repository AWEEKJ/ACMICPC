"""
Merge Sort
Time Complexity: O(nlogn)
Space Complexity: O(n)
"""

def merge(A, B):
    result = []
    i = j = 0
    while i < len(A) and j < len(B):
        if A[i] <= B[j]:
            result.append(A[i])
            i += 1
        else:
            result.append(B[j])
            j += 1
    if A[i:]:
        result.extend(A[i:])
    if B[j:]:
        result.extend(B[j:])
    return result

def merge_sort(A):
    n = len(A)
    if n <= 1: 
        return A
    else:
        a1 = merge_sort(A[:n//2])
        a2 = merge_sort(A[n//2:])
    return merge(a1, a2)
        
if __name__ == '__main__':
    list = [5, 13, 2, 25, 7, 17, 20, 8, 4]
    print(merge_sort(list))