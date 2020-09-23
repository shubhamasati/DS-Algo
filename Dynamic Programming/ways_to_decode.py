"""
    Problem Statement: Your are given a String containg digits. you need to decode this integer string such that 
                       1 -> 'a', 2 -> 'b' ..... 26 -> 'z'.
        You have to tell in how many ways this string can be decoded.
    Example: A = '121721'
             OUTPUT: 7 {ABAGBA, ABAGU, ABQU, IQU, AUGBA, ABQBA, IAGBA}
"""

def ways_to_decode(S):
    N = len(S)

    ways = [0]*(N+1)
    ways[0] = 1
    for i in range(1, N+1):
        if i > 1 and S[i-2] != '0' and int(S[i-2:i]) <= 26:
            ways[i] += ways[i-2]
        
        if S[i-1] != '0':
            ways[i] += ways[i-1]
    return ways[N]


def main():
    S = '22613' # BBFAC VFAC BZAC BBFM VFM BZM
    print(ways_to_decode(S))

if __name__ == "__main__":
    main()
