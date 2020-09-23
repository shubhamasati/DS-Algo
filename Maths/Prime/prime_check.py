from math import sqrt

def is_prime(A):
    if A < 2:
        return (False, [])

    if A == 2: return (True, [])

    if A % 2 == 0: return (False, [2])
    
    prime = True
    divisor = []

    x = sqrt(A)
    for i in range(3, int(x), 2):
        if A % i == 0:
            prime = False
            divisor.append(i)

    return prime, divisor

def main():
    A = 1000000007
    
    prime, divisor = is_prime(A)

    if prime:
        print('Number is prime')
    else:
        print("This Number is not Prime. It is divisible by:" , divisor)

if __name__ == '__main__':
    main()