def find(a, parent):
    while parent[a] != a:
        a = parent[a]
    return a

def union(a, b, parent, size):
    a_par = find(a, parent)
    b_par = find(b, parent)

    if a_par == b_par: return 1

    if size[a_par] < size[b_par]:
        parent[a_par] = b_par
        size[b_par] += size[a_par]
    else:
        parent[b_par] = a_par
        size[a_par] += size[b_par]
    return 0

def main():
    N, Q = map(int, input().split())

    parent = [ i for i in range(N+1)]
    size = [ 1 for _ in range(N+1)]
    sad = 0
    for i in range(Q):
        u, v = map(int, input().split())
        sad += union(u, v, parent, size)
    print(sad)

if __name__ == "__main__":
    main()