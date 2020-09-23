from heapq import heapify, heappop, heappush, heapreplace
class Node:
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight

    def __lt__(self, other):
        return self.weight < other.weight

def main():
    A = 6
    B = [   [0, 4, 9],
            [3, 4, 6],
            [1, 2, 1], 
            [2, 5, 1], 
            [2, 4, 5], 
            [0, 3, 7], 
            [0, 1, 1], 
            [4, 5, 7], 
            [0, 5, 1] 
        ] 
    C = 4
    
    G = [ [] for _ in range(A)]

    for i, j, k in B:
        G[i].append((j,k))
        G[j].append((i,k))


    ans = [-1 for _ in range(A)]
    
    visited = [ False for _ in range(A)]

    q = []

    d = {}

    for i in range(A):
        if i == C:
            q.append(Node(i, 0))
            d[i] = 0
        else:
            d[i] = float('inf')
    
    heapify(q)
    
    while q:
        node = heappop(q)
        cur_node, w = node.node, node.weight
        
        if not visited[cur_node]:
            for n, w in G[cur_node]:
                if not visited[n]:
                    distance_by_cur = w + d[cur_node] 
                    if distance_by_cur < d[n]: 
                        d[n] = distance_by_cur
                    heappush(q, Node(n, distance_by_cur))
        visited[cur_node] = True
    print(d)
if __name__ == '__main__':
    main()