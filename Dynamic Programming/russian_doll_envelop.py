"""
     problem statement: Given a matrix of integers A of size N x 2 describing dimensions of N envelopes, 
     where A[i][0] denotes the height of the ith envelope and A[i][1] denotes the width of the ith 
     envelope. One envelope can fit into another if and only if both the width and height of one 
     envelope is greater than the width and height of the other envelope. 
     Find the maximum number of envelopes you can put one inside other.
"""
def LIS_cal(A):
    N = len(A)
    LIS = [1]*(N+1)
    ans = 0    
    LIS[0] = 1
    for  i in range(N):
        for j in range(i):
            if A[j] < A[i]:
                LIS[i] = max(LIS[i], LIS[j]+1)
        ans = max(ans, LIS[i])
    return ans

def russian_doll_envelop(h, w):
    s = list(zip(h, w))
    s.sort(key = lambda x: (x[0], -x[1]))
    
    h = [i[1] for i in s]
    return LIS_cal(h)

def main():
    h = [6, 5, 6, 2]
    w = [4, 3, 7, 2]
    print(russian_doll_envelop(h, w))

if __name__ == "__main__":
    main()

