def merge_sort(A):
    N = len(A) - 1
    m = 1
    while m < N+1:
        for s in range(0, N-m+1, 2*m):
            start = s
            mid = s + m - 1
            end = min(mid + m, N)

            T = [0]*(end-start+2)
            idx = 0
            
            i = start
            j = mid + 1

            while i <= mid and j <= end :
                if A[i] < A[j]:
                    T[idx] = A[i]
                    i += 1
                else:
                    T[idx] = A[j]
                    j += 1
                idx += 1
            
            while i < mid + 1:
                # print(idx, i)
                T[idx] = A[i]
                idx += 1
                i += 1

            while j <= end:
                T[idx] = A[j]
                idx += 1
                j += 1

            for k in range(idx):
                A[start + k] = T[k]
        m += m
def main():
     A = [1,5,3,4,5,6,9,7,4,1,10,15,12,14]
     merge_sort(A)
     print(A)

if __name__ == '__main__':
    main()