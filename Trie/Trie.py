class Node:
    def __init__(self):
        self.nodes = {}
        self.isEnd = False
        self.freq = 0

def insert(root, word):
    t = root
    for c in word:
        if c in t.nodes:
            t = t.nodes[c]
            t.freq += 1
        else:
            t.nodes[c] = Node()
            t = t.nodes[c]
            t.freq += 1
    t.isEnd = True

def is_valid_word(root, word):
    t = root
    for c in word:
        if c in t.nodes:
            t = t.nodes[c]
        else:
            return False
    return t.isEnd

def unique_prefix(root, word):
    t = root
    pre = ''
    for c in word:
        if c in t.nodes:
            t = t.nodes[c]
            pre += c
            if t.freq == 1:
                return pre
            

root = Node()

A = ['TRIE', 'THE', 'TRY', 'PLOT', 'PLAY', 'PLATE', 'CAT']

for word in A:
    insert(root, word)

print(is_valid_word(root, 'PLATE'))

unique_pre = []

for i in A:
    unique_pre.append(unique_prefix(root, i))
print(unique_pre)






