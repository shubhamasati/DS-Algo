
t = int(input())

N, R = map(int, input().split())

G = [ [] for _ in range(N+1)]
for  _ in range(R):
    u, v  = map(int, input().split())
    G[u].append(v)

a, b , k = map(int, input().split())

q = []
visited = []
q.append(a)

paths = [0]*(N+1)
paths[a] = 1

while q:
    cur_node = q.pop(0)
    for n in G[cur_node]:
        if (n, cur_node) not in visited:
            paths[n] += paths[cur_node]
            visited.append((n, cur_node))
            q.append(n)
# print(paths)
if paths[b] >= k:
    print('YES')
else:
    print('NO') 

"""

1
5 6
1 2
1 4
2 3
4 3
4 5
3 5
1 5 2

"""