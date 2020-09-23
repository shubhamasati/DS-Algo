
def main():
    
    N, M, C_LIB, C_ROAD = map(int, input().split())

    G = [ [] for _ in range(N+1)]

    for _ in range(M):
        u, v = map(int, input().split())
        G[u].append(v)
        G[v].append(u)

    visited = [ False for _ in range(N+1)]

    q = []
    
    total_cost = 0
    for i in range(1, N):
        cost = 0
        nodes_in_component = 0

        if not visited[i]:

            q.append((i, 0))
            visited[i] = True
            
            cost += C_LIB;
            nodes_in_component = 1

            while q:
                cur_node, d = q.pop(0)

                for n in G[cur_node]:
                    if not visited[n]:
                        cost += C_ROAD
                        nodes_in_component += 1

                        q.append((n, d+1))
                        visited[n] = True

            total_cost += min(cost, nodes_in_component*C_LIB)
    
    print(total_cost)


if __name__ == '__main__':
    main()


"""
# Input-I
3 3 2 1
1 2
3 1
2 3

# Input-II
6 6 2 5
1 3
3 4
2 4
1 2
2 3
5 6

"""