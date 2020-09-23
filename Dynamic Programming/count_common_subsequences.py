"""
    Problem Statement: given two strings A and B, Count all the common subsequnces for both the strings.
"""
def common_subsequences(A):
    B = A[::-1]
    
    N = len(A)

    count = [ [0]*(N+1) for _ in range(N+1)]
    
    for i in range(1, N+1):
        for j in range(1, N+1):
            if A[i-1] == B[j-1]:
                count[i][j] = count[i][j-1] + count[i-1][j] + 1
            else:
                count[i][j] = count[i-1][j] + count[i][j-1] - count[i-1][j-1]
    # print(count)
    return count[N][N]


def main():
    A = "xyzx" 
    print(common_subsequences(A))                                                                                                        
    # d = common_subsequences(A)
    # ans = []
    # for i in range(1, len(A)+1):
    #     ans.append(d[i-1][len(A) - i] + 1)
    # print(ans)



if __name__ == "__main__":
    main()

# 1 38 708 10169 103923 953686 5922435 36718298 209942082 263060872 969578491 807748233 212769789 664066929 -414863409