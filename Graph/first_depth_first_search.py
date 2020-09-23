def DFS(G, S, D, N):

    q = []

    visited = [False]*(A+1)

    q.append(S)
    visited[S] = True



def main():
    A = [1, 1, 2 ]
    B = 1
    C = 2

    N = len(A)
    G = [ [] for _ in range(N)]

    for i, v in enumerate(A):
        G[v].append(i+1)

    print(find_path(G, B, C))
if __name__ == '__main__':
    main()