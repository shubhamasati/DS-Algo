def insert(s, trie):
    t = trie
    for i in s:
        if i not in t:
            t[i] = {}
        t = t[i]
    t['end'] = True

def complete(word, trie, d):
    t = trie
    for i in t:
        if i == 'end':
            continue
        if 'end' in t[i]:
            d.append(word + i)
        complete(word + i, t[i], d)


def find(s, trie, d):
    t = trie
    i = 0
    for i in range(len(s)):
        if s[i] in t:
            t = t[s[i]]
        else:
            t = None
            break;
    if not t:
        d.append(0)
        return
    if 'end' in t:
        d.append(s)
    complete(s, t, d)

t = int(input())

for _ in range(t):
    n = int(input())
    dic = input().split()

    trie = {}

    for i in dic:
        insert(i, trie)
    
    word = input()

    temp = ""
    for i in word:
        temp += i
        d = []
        find(temp, trie, d)
        
        for i in d:
            print(i, end = " ")
        print()
        
