#     Solution Approach-II
# -----------------------------
"""
    1. if stack is empty or element is greater than the top of the statck add element to stack.
    2. if element is less than the top of the stack keep removing the elements from stack until top of stack is equal to smaller than the element.
    3. Each time we remove element calculate the area:
        a. If stack is empty:
              area = A[top]*i
        b. If stack is not empty:
              area = A[top]*(i - top - 1)
"""

def calculate_area(A):
    s = []
    ans = -1
    top = 0
    i = 0
    while i < len(A):
        if len(s) == 0 or A[i] >= s[-1]:
            s.append(i)
            i += 1
        else:
            top = s.pop()
            if not len(s):
                ans = max(ans, A[top]*i)
            else:
                ans = max(ans, A[top]*(i-top-1))
            
    while len(s):
        top = s.pop()
        if not len(s):
             ans = max(ans, A[top]*i)
        else:
            ans = max(ans, A[top]*(i-top))
    
    return ans

print(calculate_area([1,2,3]))
        
            
            
    
    
