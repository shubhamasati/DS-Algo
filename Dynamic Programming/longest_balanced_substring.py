"""
    Problem Statement: Given a string A made up of multiple brackets of type "<>" , "[]" , "()" and "{}" 
                       find the length of the longest substring which forms a balanced string . 
    Conditions for a string to be balanced :
        1. Blank string is balanced ( However blank string will not be provided as a test case ).
        2. If B is balanced : (B) , [B] , {B} and <B> are also balanced.
        3. If B1 and B2 are balanced then B1B2 i.e the string formed by concatenating B1 and B2 is also balanced.
"""

def LBS(S):

    long_balanced = [0]*(len(S))
    

def main():
    s = input()
    print(LBS(s))


if __name__ == "__main__":
    main()