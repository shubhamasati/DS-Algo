def if_path_exist(G, S, A):

    q = []

    visited = [False]*(A+1)

    q.append(1)
    visited[1] = True

    while q:
        cur_node = q.pop(0)

        if cur_node == A:
            return True

        for n in G[cur_node]:
            if not visited[n]:
                q.append(n)
                visited[n] = True
    return False

def main():

    # # Input-1
    # A = 5
    # B = [   
    #         [1, 2],
    #         [4, 1],
    #         [2, 4], 
    #         [3, 4], 
    #         [5, 2], 
    #         [1, 3] 
    #     ]


    # Input-2
    A = 5
    B = [  [1, 2],
           [2, 3],
           [3, 4], 
           [4, 5] 
        ]
    
    G = [ [] for i in range(A+1)]

    for u, v in B:
        G[u].append(v)

    print(if_path_exist(G, 1, A))
if __name__ == '__main__':
    main()