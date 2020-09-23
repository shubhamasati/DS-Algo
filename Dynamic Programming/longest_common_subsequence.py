"""
    Problem Statement: you are given two strings A and B. find the lenghth of longest subsequence which is 
                       common in both the strings.

    Expale: 
           A: 'kdfukeid'
           B: 'sjdhifd'
    ouput: 3 ("did")
"""

def LCS(A, B):
    N = len(A)
    M = len(B)

    LCS_LEN = [ [0]*(N+1) for _ in range(M+1)]

    for i in range(1, M+1): #string b
        for j in range(1, N+1):
            if A[j-1] == B[i-1]:
                LCS_LEN[i][j] = LCS_LEN[i-1][j-1] + 1 
            else:
                LCS_LEN[i][j] = max(LCS_LEN[i-1][j-1], LCS_LEN[i-1][j], LCS_LEN[i][j-1])
            
    return LCS_LEN[M][N]

def main():
    A = "abgyfe"
    B = "dngfyk"
    print(LCS(A, B))

if __name__ == "__main__":
    main()