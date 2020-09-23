"""
Problem statement: Given a Number N. Calculate Nth fibonacci number in series.
"""


def nth_fib(N):
    """
        DP state:
            - fib[i] represents a ith term in fibonacci series.
    """
    fib = [0]*(N+1)     #List to store the results

    #Base cases
    fib[0] = 0
    fib[1] = 1

    for i in range(2, N+1):
        fib[i] = fib[i-1] + fib[i-2]
    
    return fib[N]   #returning the result ( Nth term)

def main():
    N = int(input("Enter Number: "))  #Taking input
    print(nth_fib(N))

if __name__ == "__main__":
    main()
