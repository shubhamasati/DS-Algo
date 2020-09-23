"""
    Problem Statement: Given N items. Each item has some wight w[i] and value v[i] associatd with it. you have 
                       a Knapsack of W size. you can buy the each item once and you can not buy the items more 
                       than W(knapsack size). you have to maximaize the value of bought items.
"""
def knapsack(w, v, W):
    N = len(v)

    #padding zero for 1 based indexing
    w = [0] + w
    v = [0] + v

    KS = [ [0]*(W+1) for _ in range(N+1)]

    for i in range(1, N+1):
        for j in range(1, W+1):
            if w[i] <= j:
                KS[i][j] = max(KS[i-1][j], KS[i-1][j - w[i]] + v[i])
            else:
                KS[i][j] = KS[i-1][j]
    return KS[N][W]

def main():
    v = [1, 3, 5, 6]
    w = [2, 4, 3, 5]
    W = 7
    print(knapsack(w, v, W))

if __name__ == "__main__":
    main()