
"""
    Problem Statement: Given an integer N. Return count of minimum numbers, sum of whose squares is equal to N. Example: N=6 Possible combinations are :
    
    1. (12 + 12 + 12 + 12 + 12 + 12)
    2. (12 + 12 + 22)
        So, minimum count of numbers is 3 (i.e. 1,1,2)
"""

from math import ceil, sqrt
def min_num_squares(N):
    """
        DP State: min_num_square[i] represent the minimum number of squares to make number i.
    """
    min_squares = [0]*(N+1)

    min_squares[0] = 0
    min_squares[1] = 1
    if N > 2: min_squares[2] = 2
    if N > 3: min_squares[3] = 3

    for i in range(4, N+1):
        min_squares[i] = i
        for j in range(ceil(sqrt(i)) + 1):
            min_squares[i] = min(min_squares[i], 1 + min_squares[i - j*j])
    return min_squares[-1]

def main():
    N = int(input())
    print(min_num_squares(N))

if __name__ == "__main__":
    main()