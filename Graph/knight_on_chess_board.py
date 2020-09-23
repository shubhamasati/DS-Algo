def minimum_path(A, B, C, D, E, F):

    q = []

    visited = [ [False]*(B+1) for _ in range(A+1)]

    x = [2, -2, 2, -2, -1, 1, -1, 1]
    y = [1, -1, -1, 1, 2, 2, -2, -2]

    q.append((C, D, 0))
    visited[C][D] = True
    ans = 0
    while q:
        cur_i, cur_j, t = q.pop(0)
        ans = max(ans, t)
        if cur_i == E and cur_j == F:
            return ans

        for dx, dy in zip(x, y):
            new_i, new_j = cur_i + dx, cur_j + dy
            if 0 < new_i < A+1 and 0  < new_j < B+1 and not visited[new_i][new_j]:
                visited[new_i][new_j] = True
                q.append((new_i, new_j, t+1))
    return -1

def main():
    #Input -1
    A = 8
    B = 8
    C = 1
    D = 1
    E = 8
    F = 8
    
    # #Input-2
    # A = 2
    # B = 4
    # C = 2
    # D = 1
    # E = 4
    # F = 4
    print(minimum_path(A, B, C, D, E, F))
if __name__ == '__main__':
    main()