"""
    Problem Statement: There are N houses in society. Given an array of length N, representing 
                       the Money in each house. you are a robber and you want to rob the society.
                       But there is problem that if you Rob house i then you can not rob its immediate
                       neighbours. you need to maximize the loot.
"""

def rob(A):

    """
        DP State: 
                 ~ max_loot[i] represents the maximum loot gained by robing [1 to i] houses.
    """
    max_loot = [0]*(len(A)) #list to store the results
    
    #base cases
    max_loot[0] = A[0] #if there is only one house we have no other option except robbing that only.
    max_loot[1] = max(A[0], A[1])  # if there are only two houses we will rob house with maximum Money in that.

    for i in range(2, len(A)):
        max_loot[i] = max(max_loot[i-2] + A[i],     #if we rob ith house
                                max_loot[i-1])      #if we don't rob ith house
    
    return max_loot[-1]

def main():
    A = list(map(int, input().split()))
    print(rob(A))

if __name__ == "__main__":
    main()
