def dfs(root, child, grand, B, DP):
    if not root: return 0

    ansWithout = 0

    if root in child:
        for i in child[root]:
            dfs(i, child, grand, B, DP)
            ansWithout += DP[i]
    
    ansWith = B[root]

    if root in grand:
        for i in grand[root]:
            ansWith += DP[i]
    
    DP[root] = max(ansWith, ansWithout)

def valuable_nodes(A, B):
    N = len(A)
    # A = [-1]*(N+1)
    A = [0] + A
    # for i in range(1, N):
    #     A[i+1] = A[i]
    B = [0] + B
    
    grand = dict()
    child = dict()
    DP = [0]*(N+1)

    for i in range(1, N+1):
        if A[A[i]] != 0 and A[A[A[i]]] != 0:
            if A[A[A[i]]] not in grand:
                grand[A[A[A[i]]]] = []
            grand[A[A[A[i]]]].append(i)
        if A[i] not in child:
            child[A[i]] = []
        child[A[i]].append(i)
    dfs(1, child, grand, B, DP)
    print(DP)

def main():
    A = [ 0, 1, 1, 1, 3, 3, 6, 6 ]
    B = [ 100, 2, 3, 4, 5, 6, 7, 8 ]

    print(valuable_nodes(A, B))
    

if __name__ == '__main__':
    main()