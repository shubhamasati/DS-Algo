"""
    Problem Statement: Your are given an array of integers. find the longest increasing subsequence of the array.

"""

#Time Complexity O(N2)
def LIS_cal(A):
    N = len(A)
    LIS = [1]*(N+1)
    ans = 0    
    LIS[0] = 1
    for  i in range(N):
        for j in range(i):
            if A[j] < A[i]:
                LIS[i] = max(LIS[i], LIS[j]+1)
        ans = max(ans, LIS[i])
    return ans
    
def main():
    A = [2, 6, 4, 3, 7, 5, 8, 9]
    print(LIS_cal(A))


if __name__ == "__main__":
    main()
