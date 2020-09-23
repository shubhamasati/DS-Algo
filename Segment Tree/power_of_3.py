""" 
    Power of 3
    ----------

Given a binary string A of size N and an integer matrix B of size Q x 3. Matrix B had Q queries:
For queries of type B[i][0] = 1, flip the value at index B[i][1] in A if and only if the value at that 
index is 0 and return -1.
For queries of type B[i][0] = 0, Return the value of the binary string from index B[i][1] to B[i][2] modulo 3.
Note: Rows are numbered from top to bottom and columns are numbered from left to right.

"""
def calculate_power():
    m = {}
    m[0] = 1
    for i in range(1, 100000):
        m[i] = (m[i-1] << 1) % 3
    return m
    
def build(idx, start, end):
    if start == end: tree[idx] = int(s[start])
    else:
        m = (start + end)//2
        lc = idx*2 + 1
        rc = idx*2 + 2

        build(lc, start, m)
        build(rc, m+1, end)

        tree[idx] = (tree[lc] * d[end - m]) + tree[rc]

def query(idx, start, end, L, R):
    # print('index', start, end)
    #No overlap
    if end < L or R < start: return 0
    
    #Complete Overlap
    elif L <= start and end <= R: return tree[idx]

    m = (start + end)//2

    lc = idx*2 + 1
    rc = idx*2 + 2

    l = query(lc, start, m, L, R)
    r = query(rc, m + 1, end, L, R)

    
    if R < m:
        return l
        # return (l * d[end - m]) + r
    steps = (min(R, end) - m)
    # print(l, r, steps)
    # print('val', (l << steps) + r)
    return (l * d[steps]) + r
    

def update(idx, start, end, i):
    if start == end: 
        if tree[idx] == 0:
            tree[idx] = 1
    else:
        m = (start + end)//2

        lc = idx*2 + 1
        rc = idx*2 + 2
        
        if start <= i and i <= m:
            update(lc, start, m, i)
        else:
            update(rc, m+1, end, i)

        tree[idx] = (tree[lc]* d[end - m]) + tree[rc]
        return -1
        
s = '10010'
s = list(s)
tree = [-1]*(4*len(s))

d = calculate_power()
build(0, 0, len(s)-1)
print(tree)
# print(tree)
# # print(tree)
# print(query(0, 0, len(s)-1, 2, 5))
# print(query(0, 0, len(s)-1, 1, 5))
# print(query(0, 0, len(s)-1, 2, 4))
# print(query(0, 0, len(s)-1, 1, 4))
# print(update(0, 0, len(s)-1, 1))
# print(tree)
print(update(0, 0, len(s)-1, 1))
# print(tree)
# print(s)
print(query(0, 0, len(s)-1, 0, 4))

print(update(0, 0, len(s)-1, 1))
print(query(0, 0, len(s)-1, 0, 3))
# print(query(0, 0, len(s)-1, 2, 3) % 3)

# print(query(0, 0, len(s)-1, 0, 4) % 3)
# print(update(0, 0, len(s)-1, 1))
# print(query(0, 0, len(s)-1, 0, 3) % 3)

