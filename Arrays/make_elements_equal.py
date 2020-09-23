"""
  You are given circular array of N elements. you have to make this array elements equal with
  minimum number of operation. here is opeartion which you can perform.

  A[i] can be replaced with A[i-1] or A[i] can be replaced with A[i+1] since the arary is circular
  there exist a opeartion for first and last element also.

  example:
        A: [1,1,2,2]
        output = 2 (replace A[0] with A[3] and A[1] with A[2])
"""

def find_majority_elemennts(A):
    d = {}
    maj_count = 0
    maj_elements = []
    for i in A:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1
        
        if d[i] > maj_count:
            maj_count = d[i]
    
    for i in d:
        if d[i] == maj_count:
            maj_elements.append(i)
    return maj_elements

def make_equal(a):
    
    maj_elements = find_majority_elemennts(a)
    
    ans = float('inf')

    for v in maj_elements:
        c = 0
        A = a.copy()
        while True:
            temp = []
            for i in range(len(A)):
                if A[i] != v:
                    temp.append(i)
            
            if len(temp) == 0:
                break
            
            index_to_change = []
            for i in temp:
                if i == 0:
                    if A[-1] == v or A[i+1] == v:
                        index_to_change.append(i)
                
                elif i == len(A) -1:
                    if A[0] == v or A[i-1] == v:
                        index_to_change.append(i)
                
                else:
                    if A[i-1] == v or A[i+1] == v:
                        index_to_change.append(i)
            c += 1
            for i in index_to_change:
                A[i] = v
        ans = min(ans, c)
    return ans

def main():
    A = [1,2,3,4,5,5,6]
    ans = make_equal(A)
    print(ans)

if __name__ == "__main__":
    main()

    