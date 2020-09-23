"""
    Problem Statement: Problem Statement: Given N items. Each item has some wight w[i] and value v[i] associatd with it. you have 
                       a Knapsack of W size. you can buy the each item once and you can not buy the items more 
                       than W(knapsack size). you have to maximaize the value of bought items.
    
    Constraints:
      1 <= N <= 500
      1 <= v[i] < 50
      1 <= w[i] < 10^6
      1 <= W <= 10^6
"""

# Note: If we solve this question using standard knapsack means using number of items and knapsack size
#       then this will give TLE ( 500 * 10^6 ==  5*10^8)


# Solution: here we use item index and profit to calculate answer.
# Maximum profit we can by buying all items is 500*50 == 25000 and our item indexes is maximum 500.
# so our solution will rum in 25000 * 500 == 12500000 = ~ 12*10^6

def knapsack(w, v, W):
    max_profit = max(v)

    N = len(v)

    KS = [ [0]*(max_profit*N + 1) for _ in range(N+1)]
    

def main():
    v = [1, 3, 5, 6]
    w = [2, 4, 3, 5]
    W = 7
    print(knapsack(w, v, W))

if __name__ == "__main__":
    main()



