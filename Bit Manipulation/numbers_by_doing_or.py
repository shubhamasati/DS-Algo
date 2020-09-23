from math import log
# A = int(input())
# B = int(input())
A = 9
B = 19

cnt = 0
bits = int(log(A, 2)) + 1

temp = []

for i in range(bits, -1, -1):
    if B >> i & 1 == 0:

        if A >> i & 1 == 1:
            if A not in temp:
                temp.append(A)
                cnt += 1
        else:
            if A >> i & 1 == 0 and A + (1 << i) < B:
                if A + (1 << i) not in temp:
                    cnt += 1
                    temp.append(A + (1 << i))

print(B - A + 1 + 2**cnt - 1)
