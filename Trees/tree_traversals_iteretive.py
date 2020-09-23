class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
    
def construct_tree():
    t = Node(1)
    t1 = Node(2)
    t2 = Node(3)
    t.left = t1
    t.right = t2
    t1.left = Node(4)
    t1.right = Node(5)
    t2.right = Node(7)
    return t

def preorder_traversal(root):
    
    if not root:
        return []
    ans = []
    s = [root]
    while s:
        x = s.pop()
        ans.append(x.val)
        if x.right: s.append(x.right) #if root.right
        if x.left: s.append(x.left) #if root.left
    return ans

def inorder_traversal(root):
    if not root:
        return []
    ans = []
    s = []

    while True:
        if root:
            s.append(root)
            root = root.left
        elif s:
            root = s.pop()
            ans.append(root.val)
            root = root.right
        else:
            break          
    return ans

def postorder_traversal(root):
    if not root:
        return []
    
    s = []
    ans = []

    while True:

        if root:
            s.append(root)
            root = root.left
        
        else:
            root = s.pop()
            if root.right:
                


def main():
    t = construct_tree()
    print('This is Pre-order Traversal:')
    print(preorder_traversal(t))
    print('This is In-order Traversal:')
    print(inorder_traversal(t))   

if __name__ == "__main__":
    main()