def partition(A, start, end):
    if start == end: 
        return start

    pivot = A[end]
    i = start
    j = end - 1

    for j in range(start, end):
        if A[j] < pivot:
            A[i], A[j] = A[j], A[i]
            i += 1

    A[i], A[end] = A[end], A[i]

    return i

def quick_sort(A, start, end):
    
    if start < end:
        p = partition(A, start, end)
        quick_sort(A, start, p-1)
        quick_sort(A, p+1, end)

def main():
    A = [4,1,7,6,2,3,8,9,5, 15, 14, 12, 13, 19, 57, 35, 72, 12]
    quick_sort(A, 0, len(A)-1)
    print(A)
if __name__ == "__main__":
    main()