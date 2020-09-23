
def main():
    N, M, K = map(int, input().split())

    G = [ [] for _ in range(N+1)]

    for i in range(M):
        u, v, c = map(int, input().split())
        G[u].append((v, c))
        G[v].append((u, c))

    DP = [ [float('inf')]*(K+1) for _ in range(N+1)]
    
    for i in range(K+1):
        DP[1][i] = 0

    visited = set()
    q = []
    q.append((1, 0))

    while q:
        cur_node, d = q.pop(0);
        for n, w in G[cur_node]:
            if (n, cur_node)not in visited:
                cur_d = d + 1
                DP[n][0] = min(DP[n][0], DP[cur_node][0] + w)
                for i in range(1, K+1):
                    DP[n][i] = min(DP[n][i], min(DP[cur_node][i-1], DP[cur_node][i] + w))
                q.append((n, cur_d))
                visited.add((n, cur_node))
    
    for i in DP[1:]:
        if i[k] == float('inf'):
            print(0, end = ' ')
        else:
            print(i[K], end = ' ')

if __name__ == '__main__':
    main()

# Input
# Input
"""
12 15 1
1 3 6
1 4 4
1 2 8
3 5 9
4 5 9
5 9 1
9 8 3
8 7 6
8 6 2
7 6 5
6 2 6
1 10 1
10 11 1
11 12 15
12 9 1

"""