def check_bipartite(G, A):
    #G adjecency list
    #Number of nodes in graph

    visited = [False]*(A)

    color = [set(), set()]

    q = []

    for i in range(A):
        if not visited[i]:
            q.append(i)
            color[0].add(i)

            while q:
                cur_node = q.pop(0)
                visited[cur_node] = True

                cur_color = 1 if cur_node in color[1] else 0
                
                for n in G[cur_node]:
                    if not visited[n]:
                        q.append(n)
                        if n in color[cur_color]:
                            return False
                        if n not in color[0] and n not in color[1]:
                            color[1 - cur_color].add(n)

    print(color)
    return True# #output2: True

def main():
    # #input 1
    # A = 3
    # B = [ [0, 1], [0, 2], [1, 2]]
    # #output1: False

    # #Input 2
    # A = 2
    # B = [[0, 1]]
    # #output2: True


    #input 3
    A = 10
    B = [[7, 8], [1, 2], [0, 9], [1, 3], [6, 7], [0, 3], [2, 5], [3, 8], [4, 8]]
    #output3: True

    G = [ [] for _ in range(A)]

    for u, v in B:
        G[u].append(v)
        G[v].append(u)
    
    print(G)
    print(check_bipartite(G, A))


if __name__ == '__main__':
    main()