"""
    Problem Statement: You are given a string S. and you are given large number of queries Q containing two elements
                       i and j. you have to tell for every query whether the substring of S from index i to j is palindrome
                       or not. if substring is palindrome return 1 else 0.
           Q can be large as 100000.
"""
def check_palindrome(S):

    N = len(S)
    palindrome = [ [False]*(N) for _ in range(N)]

    for i in range(N):
        palindrome[i][i] = True
        if i + 1 < N:
            # print(i, i+1, S[i] == S[i+1])
            palindrome[i][i+1] = S[i] == S[i+1]
    # print(palindrome[3][4])
    """  
         S = "SHUBBBUHS"

         i                                   j
         ( , i+1, i+2, ............j-2, j-1, )
         S    H    U     B B B      U    H   S
         
         subtring form i to j to be palindrome, substring (from i+1 to j-1) should be palindrom. so our dp state will be

                dp[i][j] == True if (dp[i+1][j-1] && S[i] ==  S[j]) else False
    """

    for l in range(3, N+1):
        for i in range(0, N):
            j = i + l - 1
            if j < N and i + 1 < N:
                palindrome[i][j] = True if palindrome[i+1][j-1] and S[i] == S[j] else False
    return palindrome

def main():

    S = "ababb"
    N = len(S)
    Q = [
           [0,6],
           [1,5],
           [4,5],
           [1,4],
           [3,4],
           [2,4],
        ]

    d = check_palindrome(S)
    # for i, j in Q:
    #     print(d[i][j])

    dp = [i for i in range(N)]
    dp = [-1] + dp
    for i in range(N):
        for l in range(1, N+1):
            if d[i-l+1][i]:
                dp[i+1] = min(dp[i-l+1] + 1, dp[i+1])
    print(dp)
    print(dp[-1])
            
if __name__ == "__main__":
    main()