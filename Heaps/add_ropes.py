from heapq import heappop, heapify, heappush

A = [1,2,3,4]
heapify(A)

ans = 0
while len(A):
    t = heappop(A) + heappop(A)
    ans += t
    if len(A) == 0:
        break
    heappush(A, t)
print(ans)



