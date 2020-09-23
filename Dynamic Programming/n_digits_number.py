"""
"""
def n_digit_number(A, B):

    count = [ [0]*(B+1) for i in range(A+1)]

    for i in range(10):
        if i <= B:
            count[1][i] = 1

    for i in range(2, A+1):
        for j in range(B+1):
            for k in range(1, 10):
                if k <= j:
                    count[i][j] += count[i-1][j - k]
    return count[A][B]        

def main():
    A = 2
    B = 4
    print(n_digit_number(A, B))
if __name__ == "__main__":
    main()