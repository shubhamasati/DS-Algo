def kadane(A):
    max_so_far = 0
    cur_max = 0

    for i in range(len(A)):
        cur_max += A[i]
        cur_max = max(0, cur_max)
        max_so_far = max(cur_max, max_so_far)
    return max_so_far

def max_submatrix(A):
    N = len(A)
    M = len(A[0])
    ans = 0
    for L in range(N):
        temp = [0]*(N)
        for R in range(L, M):
            for k in range(N):
                temp[k] += A[k][R]
            cur_max = kadane(temp)
            ans = max(ans, cur_max)
    return ans
            
def main():
    A = [
            [1, 2, -1, -4, -20],
            [-8, -3, 4, 2, 1],
            [3, 8, 10, 1, 3],
            [-4, -1, 1, 7, -6],
        ]
    print(max_submatrix(A))

if __name__ == "__main__":
    main()