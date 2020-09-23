"""
Given two arrays of strings A of size N and B of size M. 
Return a binary string C where C[i] = '1' if B[i] can be found in dictionary A using exactly one 
modification in B[i], Else C[i] = '0'. 
Note: modification is defined as converting a character into another character.
"""

class Node:
    def __init__(self):
        self.nodes = {}
        self.isEnd = False
        self.flag = 0
    
def insert(root, word):
    t = root
    s = []
    for c in word:
        if c in t.nodes:
            t = t.nodes[c]
        else:
            t.nodes[c] = Node()
            t = t.nodes[c]
        s.append(t)
    t.isEnd = True
        
def check(root, word):
    op = 0
    op_p = False
    for c in word:
        # print(c, root.nodes, op_p)
        # if op_p:
        #     # print('inside')
        #     not_found = True
        #     for i in root.nodes:
        #         print(c, root.nodes[i].nodes)
        #         if c in root.nodes[i].nodes:
        #             # print('inside')
        #             root = root.nodes[i]
        #             op_p = False
        #             not_found = False
        #             # print('after', root.nodes,op_p, not_found)
        #             break
                    
        #     if not_found: return False
        # print(c, root.nodes)
        if c in root.nodes:
            root = root.nodes[c]
        else:
            op += 1
            for i in root.nodes:
                root = root.nodes[i]
    
    return True if op == 1 else False

# A = ['data', 'circle', 'cricket']
# B = ['date', 'circel', 'crikket', 'data', 'circl']


A = ['hello', 'world', 'shukla', 'shukta']
B = ['hella', 'pello', 'pella']

# A = [ "tripti", "shukla", "shukta", "akshay", "dixit", "naithani", "godani", "kushagra", "makhan", "modiji", "yogiji", "kohli" ]
# B = [ "tripta", "shukta", "shukla", "shukka", "dickshit", "dikit", "kitti", "kohla", "modija", "nathani", "maithani", "akshat", "akshara", "tript" ]

root = Node()

for w in A:
    insert(root, w)

print(check(root, 'shukta'))
# ans = []
# for w in B:
#     ans.append(int(check(root, w)))
# print(ans)