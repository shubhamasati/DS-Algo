""""
    Problem Statement: Given two sequences A and B, count number of unique ways in sequence A, to form a subsequence
                       that is identical to the sequence B. 
    Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting
    some (can be none) of the characters without disturbing the relative positions of the remaining characters.
    (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

    Example: A: "rabbbit"
             B: "rabbit"
    Output: 3 ("ra_bbit", "rab_bit", "rabb_it")
"""
def distinct_subsequence(S: str, T: str) -> int:
    S_len = len(S) #source string length
    T_len = len(T) #target string length

    unique_ways = [ [0]*(T_len+1) for _ in range(S_len+1)]

    for i in range(S_len+1):
        unique_ways[i][0] = 1  #if target is null  there is only one ways
    
    for i in range(1, S_len+1):
        for j in range(1, T_len+1):
            #Case-1(both character natches)
            if S[i-1] == T[j-1]:
                unique_ways[i][j] = unique_ways[i-1][j] + unique_ways[i-1][j-1]
            else:
                unique_ways[i][j] = unique_ways[i-1][j]
    # print(unique_ways)
    return unique_ways[S_len][T_len]


def main():
    A = 'rabbbit'
    B = 'rabbit'
    print(distinct_subsequence(A, B))

if __name__ == "__main__":
    main()





