def main():

    A = [ [0 , 50 , 39],
          [-1 , 0 , 1],
          [-1 , 10 , 0] 
        ]
    
    N = len(A)

    for i in range(N):
        for j in range(N):
            if A[i][j] == -1:
                A[i][j] = float('inf')

    for k in range(N):
        for i in range(N):
            for j in range(N):
                A[i][j] = min(A[i][j] , A[i][k]  + A[k][j])

    for i in range(N):
        for j in range(N):
            if A[i][j] == float('inf'):
                A[i][j] = -1
    print(A)




if __name__ == '__main__':
    main()