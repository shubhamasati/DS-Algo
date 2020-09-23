ans = 0
vis = []
def solve(A, B):
        def helper(root, T, max_val, min_val, A):
            global ans, vis
            if not vis[root]:
                vis[root] = True
                ans = max(ans, abs(A[root] - min_val))
                ans = max(ans, abs(A[root] - max_val))
                
                for n in T[root]:
                    helper(n, T, max(A[root], max_val), min(A[root], min_val), A)
                # helper(root.right, max(root.val, max_val), min(root.val, min_val))
        
        N = len(A)
        A = [0] + A
        T = [ [] for _ in range(N+1)]
        for u, v in B:
            T[u].append(v)
            T[v].append(u)
        global vis
        vis = [False]*(N+1)
        helper(1, T, A[1], A[1], A)
        return ans


def main():
    # A = [ -59, -33, 34, 0, 69, 24, -22, 58, 62, -36, 5, 45, -19 ]
    # B =    [
    #       [10, 6],
    #       [3, 2],
    #       [12, 7],
    #       [9, 5],
    #       [2, 1],
    #       [8, 3],
    #       [7, 1],
    #       [4, 2],
    #       [6, 3],
    #       [11, 4],
    #       [5, 3],
    #       [13, 11],
    #     ]


    A = [ 71, 38, -31, 12, -33, -1, -65, -6, 3, -89 ]
    B = [
        [6, 2],
        [10, 5],
        [5, 2],
        [8, 2],
        [2, 1],
        [3, 1],
        [9, 8],
        [7, 6],
        [4, 1]
    ]
    print(solve(A, B))

if __name__ == '__main__':
    main()