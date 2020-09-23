class Node():
    def __init__(self):
        self.left = None
        self.right = None
        self.freq = 0

def insert(root, num):
    for i in range(31, -1, -1):
        bit = (num >> i) & 1
        if bit:
            if not root.right:
                root.right = Node()
            root = root.right
        else:
            if not root.left:
                root.left = Node()
            root = root.left
        root.freq += 1

def check(root, num):
    global ans
    for i in range(31, -1, -1):
        bit = (num >> i) & 1
        if bit:
            if root.left:
                ans += root.left.freq
            if not root.right:
                root.right = Node()
            root = root.right
        else:
            if not root.left:
                root.left = Node()
            root = root.left

def check2(root, num, k, i):
    if i == -1:
        return
    global ans 
    
    num_bit = (num >> i) & 1
    k_bit = (k >> i) & 1
    if num_bit:
        if k_bit:
            if root.right:
                ans += root.right.freq
            if root.left:
                check2(root.left, num, k, i-1)
        else:
            if root.right:
                check2(root.right, num , k, i-1)
    else:
        if not k_bit:
            if root.left:
                check2(root.left, num, k, i-1)
        else:
            if root.left:
                ans += root.left.freq
            if root.right:
                check2(root.right, num, k, i-1)
         
A = [1,2,3]
B = 4

global ans
ans = 0
pre_xor = [0]


root = Node()
insert(root, pre_xor[-1])

for i in range(0,len(A)):
    pre_xor.append(pre_xor[-1]^A[i])
    check2(root, pre_xor[-1], B, 31)
    insert(root, pre_xor[-1])    

print(ans)