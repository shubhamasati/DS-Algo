def compute_z(s):
    z = [0]*(n+1)
    z[1] = n
    # print(s)
    l, r, w = 0, 0, 0
    for k in range(2,n):
        
        if k < r:
            k_t = k - l + 1

            if z[k_t] == w:
                z[k] == z[k_t]
            elif k_t < w:
                z[k] = z[k_t]
            else:

        
        i = 0
        j = k - 1
        c = 0

        while j < n:
            if s[i] == s[j]:
                c += 1
                i += 1
                j += 1
            else:
                break
        z[k] = c
        if c != 0:
            l = k
            r = k + c - 1
            w = c
            
    

# T is text, P is the pattern we are looking for in text T
def search(T, P):
    s = P + T
    n = len(s)
    
    
    return z

def main():
    print(search('ababc', 'abc'))


if __name__ == "__main__":
    main()