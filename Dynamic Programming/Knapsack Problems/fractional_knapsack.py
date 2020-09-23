"""
    Problem Statement: Given N number of cakes. Each cake has some Happiness H[i] attached, and cake's weight S[i].
                       You came to buy a ckaes with KnapsacK of size S. Maximize the happiness of bought cakes.
"""
def fractional_knapsack(H, W, S):
    N = len(H) #Number of cakes

    KS = [0]*(N)

    for i in range(N):
        KS[i] = (H[i]/W[i], W[i])  #Calculating the happiness per unit of cakes.
    
    KS.sort(key = lambda x: x[0],reverse = True)
    
    i = 0
    ans = 0
    while S > 0 and i < N:
        if KS[i][1] < S:
            ans += KS[i][1]*KS[i][0]
            S -= KS[i][1]
        else:
            ans += S*KS[i][0]
            S -= S
        i += 1
    return ans


def main():
    H = [5, 6, 8, 10]
    W = [5, 4, 3, 6]
    S = 7

    print(fractional_knapsack(H, W, S))

if __name__ == "__main__":
    main()