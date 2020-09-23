"""
    Problem statement: Given an input string (s) and a pattern (p), implement regular expression
                       matching with support for '.' and '*'.
        1. '.' Matches any single character.
        2. '*' Matches zero or more of the preceding element.

        The matching should cover the entire input string (not partial).

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, 
             it becomes "aa".

"""
def match_regex(S, P):
    N = len(S)
    M = len(P)

    match = [ [False]*(M+1) for _ in range(N+1)]

    match[0][0] = True

    for i in range(1, M+1):
        match[0][i] = match[0][i-2] if  P[i-1] == '*' else False

    for i in range(1, N+1):
        for j in range(1, M+1):

            if P[j-1] == S[i-1] or P[j-1] == '.': # Matching Exactly one occuraane of character
                match[i][j] = match[i-1][j-1]
            elif P[j-1] == '*':
                match[i][j] = match[i][j-2] #matching zero occurrance of character
                
                if S[i-1] == P[j-2] or P[j-2] == '.':
                    match[i][j] = match[i][j] or match[i-1][j] # Matching multiple occurrances of character

    return match[N][M]


def main():
    S = "abcc"
    P = "a*b*cc"
    print(match_regex(S, P))
if __name__ == "__main__":
    main()