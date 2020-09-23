"""
    Problem Statement:
                      Implement wildcard pattern matching with support for ' ? ' and ' * ' for strings A and B.
        1. ' ? ' : Matches any single character.
        2. ' * ' : Matches any sequence of characters (including the empty sequence).
        The matching should cover the entire input string (not partial).

        Return 0 or 1:
            -> 0 : If the patterns do not match.
            -> 1 : If the patterns match.
        Example:     
            A = "aaa"
            B = "a*"
          Output = 1
"""

def match_regex(S, P):
    M = len(S)
    N = len(P)

    check_reg = [ [False]*(M+1) for _ in range(N+1)]

    """
        DP State: dp[i][j] = True if string till 'i' matches pattern till 'j' else False.
    """
    check_reg[0][0] = True

    #string --> j --> Row --> M
    #pattern --> i --> column --> N
    i = 0
    if P[0] == '*':
        while S[i] == S[0]:
            check_reg[0][i+1] = True
            i += 1
    # print(check_reg)
    for i in range(1, N + 1):
        j = 1
        while j < M + 1:
            cur_j = j
            if P[i-1] == '?':
                check_reg[i][j] = check_reg[i-1][j-1]
            
            elif P[i-1] != '*':    
                if S[j-1] == P[i-1]:
                    check_reg[i][j] = check_reg[i-1][j-1]
                else: check_reg[i][j] = False
            
            else:  # P[i] is '*'
                # print('here', i-1, j, check_reg[i-1][j])
                check_reg[i][j] = check_reg[i-1][j] or check_reg[i][cur_j-1]# Matching empty string(fix the string and reduce regex)

                # cur_j = j + 1
                # while cur_j < M + 1 and S[cur_j-1] == S[j-1]:
                #     check_reg[i][cur_j] = check_reg[i][cur_j-1]
                #     cur_j += 1
                #     # print(j-1, cur_j-1, S[cur_j-1], S[j-1])
                # j = cur_j - 1
            j += 1
    
    return check_reg[N][M]

def main():
    s = "aaaabcd"
    p = '*b??'
    print(match_regex(s, p))

if __name__ == "__main__":
    main()