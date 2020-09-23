def arithmetic_subsequence(A):
    
    N = len(A)  
    count = [ dict() for _ in range(N)]
    ans = 0
    for i in range(1, N):
        for j in range(i):
            com_dif = A[i] - A[j]
            sum = 0
            if com_dif in count[j]:
                sum = count[j][com_dif]
            
            if com_dif in count[i]:
                count[i][com_dif] += sum + 1
            else:
                count[i][com_dif] = 1
            ans += sum
    # print(count)
    return ans

def main():
    A = [-4, 5, 4, 0, 5, 9, 3, 4, 0, -3 ]
    print(arithmetic_subsequence(A))

if __name__ == "__main__":
    main()