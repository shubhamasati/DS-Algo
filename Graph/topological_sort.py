from heapq import heapify, heappush, heappop
def main():
    A, M = map(int, input().split())

    IN_deg = [ 0 for _ in range(A+1)]
    
    G = [ [] for _ in range(A+1)]

    h = []
    for _ in range(M):
        u, v = map(int, input().split())
        IN_deg[v] += 1
        G[u].append(v)

        
    
    for i in range(1, A+1):
        if IN_deg[i] == 0: h.append(i)
    
    heapify(h)

    topo_order = []

    while h:
        cur_node = heappop(h)
        topo_order.append(cur_node)
        for n in G[cur_node]:
            IN_deg[n] -= 1
            if IN_deg[n] == 0:
                heappush(h, n)

    print(topo_order)


if __name__ == '__main__':
    main()


"""
# input

6 6
6 3
6 1
5 1
5 2
3 4
4 2

"""