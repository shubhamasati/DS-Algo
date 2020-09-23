def built(idx, start, end):
    if start == end:
        print(idx, start, end)
        tree[idx] = A[start]
    else:
        m = start + (end - start)//2

        lc = idx*2 + 1
        rc = idx*2 + 2

        built(lc, start, m)
        built(rc, m+1, end)

        tree[idx] = min(tree[lc], tree[rc])

def query(idx, start, end, L, R):
    if end < L or R < start:
        return float('inf')
    if start >= L and end <= R:
        return tree[idx]
    else:
        m = (start + end)//2

        lc = idx*2 + 1
        rc = idx*2 + 2

        return min(query(lc, start, m, L, R), query(rc, m+1, end, L, R))

def update(idx, start, end, id, val):
    if start == end:
        A[start] = val
        tree[idx] = val
    else:
        m = (start + end)//2

        lc = idx*2 + 1
        rc = idx*2 + 2
        if id <= m:
            update(lc, start, m, id, val)
        else:
            update(rc, m+1, end, id, val)
        
        tree[idx] = min(tree[lc], tree[rc])

global tree
global A

A = [18, 10, 1, 20, 25, 4, 9, 13, 15, 6, 21, 7]
N = len(A)
tree = [-1]*(4*N - 1)

built(0, 0, N-1)
print(tree)
L = 2
R = 4
print(query(0, 0, N-1, L, R))
update(0, 0, N-1, 3, -4)
print(query(0, 0, N-1, L, R))