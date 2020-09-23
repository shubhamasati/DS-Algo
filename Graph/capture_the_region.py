def capture_region(A):
    N = len(A)
    M = len(A[0])

    q = []

    x = [0, 1, -1, 0]
    y = [1, 0, 0, -1]
    visited = []


    for i in range(N):
        for j in range(M):
            print(A[i][j])
            if A[i][j] == 'O':
                A[i][j] = '*'
    print(A)
    for i in range(N):
        if A[i][0] == '*':
            q.append((i, 0))
            visited.append((i, 0))
        if A[i][M-1] == '*':
            q.append((i, M-1))
            visted.append((i, M-1))

    for i in range(M):
        if A[0][i] == '*':
            q.append((0, i))
            visited.append((0, i))
        if A[N-1][i] == '*':
            q.append((N-1, i))
            visited.append((N-1, i))
    
    
    while(q):
        cur_i, cur_j = q.pop(0)
        A[cur_i][cur_j] = 'O'
        for dx, dy in zip(x, y):
            new_i, new_j = cur_i + dx, cur_j + dy
            if -1 < new_i < N and -1 < new_j < M and A[new_i][new_j] == '*' and (new_i, new_j) not in visited:
                q.append((new_i, new_j))
                visited.append((new_i, new_j))
    

    for i in range(N):
        for j in range(M):
            if A[i][j] == '*':
                A[i][j] = 'X'

    return A
            

def main():
    B = [ "XXX", "XOX", "XXX" ]
    A =[ list(l) for l in B]

    print(capture_region(A))

if __name__ == '__main__':
    main()