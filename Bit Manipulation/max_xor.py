def max_xor(A, B, C):
    ans = A^B
    num = 0
    print(bin(A), bin(B))
    for i in range(31, -1, -1):
        if not (A & 1 << i):  # bit is unset
            t = (num | 1 << i) #setting one bit
            # print('unset', i)
            if  t <= C:
                num = t
            
    for i in range(31, -1, -1):
        if (A & 1 << i):  # bit is unset
            t = (num | 1 << i) #setting one bit
            # print('unset', i)
            if  t <= C:
                num = t
    
    
    for i in range(31):
        if (num & 1 << i): #both the bits are set
            # t = (num & (~(1 << i) ))#unsetting one bit
            t = (num | 1 << i)
        if B <= t and t <= C:
            num = t
        else:
            break

    print(bin(num), num)
    ans = max(ans, A^num)
    print(num)      
    return ans
                    


def main():
    # A = 43391125
    # B = 160567226
    # C = 170318369

    # A = 42
    # B = 35
    # C = 68


    A = 76803321
    B = 74740263
    C = 124555901

    print(max_xor(A, B, C))
if __name__ == "__main__":
    main()


"""


0010100101100001100010010101    -- A
1001100100100000111110111010    -- B
1001111010011110011101101010    --Expec
1001011010011110011101101010    -- NUm
ans = 192937983

101010  -- A
100011  -- B
ans = 110





"""

