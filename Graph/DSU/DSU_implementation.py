def find(a, parent):
    while parent[a] != a:
        a = parent[a]
    return a

def union(a, b, parent, size):
    a_parent = find(a, parent)
    b_parent = find(b, parent)

    if a_parent != b_parent:
        if size[a_parent] < size[b_parent]:
            parent[a_parent] = b_parent
            size[b_parent] += size[a_parent]
        else:
            parent[b_parent] = a_parent
            size[a_parent] += size[b_parent]
           

def main():
    N, Q = map(int, input().split())

    parent = [ _ for _ in range(N+1)]
    size = [ 1 for _ in range(N+1) ]
    for _ in range(Q):
        u, v = map(int, input().split())
        union(u, v, parent, size)
    print(size)


if __name__ == '__main__':
    main()

"""
# Input I

10 7
1 2
3 4
3 5
2 3
6 7
8 9
7 10

"""