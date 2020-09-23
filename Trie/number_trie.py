class Node:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val

def inorder(root, s):
    if not root:
        return 
    inorder(root.left, s + '0')
    if not root.left and not root.right:
        print(s)
    
    inorder(root.right, s + '1')

def calculate(root, num):
    cur_xor = 0
    for i in range(31, -1, -1):
        bit = num >> i & 1
        if (bit and root.left) or (not bit and root.right):
            cur_xor += 1 << i
            if bit:
                root = root.left
            else:
                root = root.right
        else:
            if bit:
                root = root.right
            else:
                root = root.left
        
    return cur_xor



def insert(root, num):
    for i in range(31, -1, -1):
        bit = num >> i & 1
        if bit:
            if not root.right:
                root.right = Node(1)
            root = root.right
        else:
            if not root.left:
                root.left = Node(0)
            root = root.left

def delete(root, num):
    s = []
    for i in range(31, -1, -1):
        bit = num >> i & 1
        if bit:
            root = root.right
        else:
            root = root.left
        s.append(root)
    
    pre = s.pop()
    while s:
        root = s.pop()
        if root.right and root.left:
            if pre.val == 1:
                root.right = None
            if pre.val == 0:
                root.left = None
            return
        pre = root
        if root.right: root.right = None
        if root.left: root.left = None

def check(root, num):
    for i in range(31, -1, -1):
        bit = num >> i & 1
        if bit:
            if not root.right:
                return False
            root = root.right
        else:
            if not root.left:
                return False
            root = root.left
    return True

def solve(root, v, d, q):
    insert(root, v)
    if v in q:
        ind = q[v]
        # print(check(root, 1), check(root, 3),check(root, 5), check(root, 2), check(root, 4))
        print(v)
        inorder(root, '')
        for j in ind:
            print(j)
            ans[j] = calculate(root, E[j])

    if v in d:
        for i in d[v]:
            solve(root, i, d, q)
    delete(root, v)
                

A = 8
B = [1,1,2,2,3,3,1]
C = 5
D = [2,3,5,6,8]
E = [1,1,5,4,10]

# A = 5
# B = [ 1, 2, 3, 4 ]
# C = 3
# D = [ 5, 5, 3 ]
# E = [ 5, 3, 7 ]

ans = [0]*C
d = {}
for i, v in enumerate(B, 1):
    if v in d: d[v].append(i+1)
    else: d[v] = [i+1]
q = {}
for i in range(C):
    if D[i] in q:
        q[D[i]].append(i)
    else:
        q[D[i]]= [i]

root = Node(-1)
solve(root, 1, d, q)

print(ans)
