"""
Bob has an array A of N integers. Initially, all the elements of the array are zero. Bob asks you to perform 
Q operations on this array.

There are three types of operations that can be performed:

1 X -1: Update the value of A[X] to 2 * A[X] + 1.
2 X -1: Update the value A[X] to ⌊A[x]/2⌋ , where ⌊⌋ is Greatest Integer Function.
3 X Y: Take all the A[i] such that X <= i <= Y and convert them into their corresponding binary strings. 
       Now concatenate all the binary strings and find the total no. of '1' in the resulting string.
"""

def update(idx, start, end, i, op):
    if start == end:
        if op == 1:
            tree[idx] += 1
            # A[start] += 1
        if op == 2:
            tree[idx] -= 1
            # A[start] += 1
    else:
        m = (start + end)//2

        lc = idx*2 + 1
        rc = idx*2 + 2
        
        if start <= i and i <= m:
            update(lc, start, m, i, op)
        else:
            update(rc, m+1, end, i, op)
        
        tree[idx] = tree[lc] + tree[rc]

def query(idx, start, end, L, R):
    
    #No Overlap
    if end < L or R < start:
        return 0
    
    #Complete Overlap
    elif L <= start and end <= R:
        return tree[idx]
    
    #Partial Overlap
    else:
        m = (start + end)//2

        lc = idx*2 + 1
        rc = idx*2 + 2
        
        return query(lc, start, m, L, R) + query(rc, m+1, end, L, R)


A = 5
tree = [0]*(4*A)
B = [
    [1, 1, -1],
    [1, 2, -1],
    [3, 1, 3],
    [2, 1, -1],
    [3, 1, 3],  
]

for i, j, k in B:
    if i == 1 or i == 2:
        update(0, 0, A-1, j, i)
    else:
        print(query(0, 0, A-1, j, k))
