"""
    Problem Statement: Your are given a set of coins with Infinite availability, and you are given one value N
                       find the number of ways to form the value N using given coins.
     1. when order of coins matters.
     2. when order of coins do not matter.

     Example: N = 5, C = [1,3,4]
             1. when order matter: 6 ways { (1,1,1,1,1), (1,1,3), (1,3,1),(3,1,1),(1,4), (4,1)}
             2. when order do not matter: 3 Ways {(1,1,1,1,1), (3,1,1), (4,1)}
"""

def ways_to_form(N, C):
    coins_len = len(C)
    
    # Case-I (when order matter)
    ways1 = [0]*(N+1)
    ways1[0] = 1

    for i in range(1, N+1): #select domination to form
        for j in range(coins_len):
            if C[j] <= i:
                ways1[i] += ways1[i - C[j]]
    return ways1[N]

    # Case-II (when order do not matter)
    ways2 = [0]*(N+1)
    ways2[0] = 1

    for j in range(coins_len): #select domination to form
        for i in range(C[j], N+1):
            ways2[i] += ways2[i - C[j]]
    return ways2[N]

def main():
    N = 5
    C = [1,3,4]
    print(ways_to_form(N, C))

if __name__ == "__main__":
    main()