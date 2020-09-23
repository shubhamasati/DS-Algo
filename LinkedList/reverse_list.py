class Node:
    def __init__(self, v):
        self.val = v
        self.next = None

def reverse(head, beg, end):
    
    pre = None
    cur = head
    st = None
    pre_end = None
    
    cnt = 1
    while cnt < end:
        if cnt < beg:
            pre = cur
            st = cur.next
        
        pre_end = cur
        cur = cur.next
        cnt += 1
        
    # cur = st.next
    
    t = cur
    while st != cur:
        temp = st.next
        st.next = t
        t = st
        st = temp
    pre = t
    return head


global head 

head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)
head.next.next.next.next.next = Node(6)

temp = head
while temp:
    print(temp.val, end = " ")
    temp = temp.next
print()

temp = reverse(head, 2, 4)
while temp:
    print(temp.val, end = " ")
    temp = temp.next
print()


