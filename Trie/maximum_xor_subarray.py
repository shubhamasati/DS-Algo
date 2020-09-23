class Node:
    def __init__(self):
        self.left = None
        self.right = None
        self.index = None
    

def insert(root, num, index):
    
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
    root.index = index

def query(root, num):

    cur_xor = 0

    for i in range(31, -1, -1):
        bit = (num >> i) & 1

        if bit:
            if root.left:
                root = root.left
                cur_xor += 1 << i
            else:
                root = root.right
        else:
            if root.right:
                root = root.right
                cur_xor += 1 << i
            else:
                root = root.left
    return cur_xor, root.index
        


# A = [1, 4, 3]
A = [6, 7]

pre_xor = 0
max_xor = float('-inf')

ans = [0, 0]

root = Node()
insert(root, 0, -1)

for i in range(len(A)):
    pre_xor = pre_xor^A[i]
    insert(root, pre_xor, i)

    x, ind = query(root, pre_xor)
    
    if x > max_xor:
        max_xor = x
        if ind == -1:
            ans = [1, i+1]
        else:
            ans = [ind+2, i+1]
print(ans)

