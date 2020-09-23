def up_heapify(i, A):
    p = (i - 1)//2
    while p > -1 and A[p] > A[i]:
        A[p], A[i] = A[i], A[p]
        i = p
        p = (i - 1)//2

def down_heapify(i, A):
    l = i*2 + 1
    r = i*2 + 2

    if last == 2:
        if A[0] > A[1]:
            A[0], A[1] = A[1], A[0]

    while (l < last and r < last):
        if A[l] > A[i] and A[r] > A[i]:
            break
        else:
            if A[l] < A[r]:
                A[l], A[i] = A[i], A[l]
                i = l
            else:
                A[r], A[i] = A[i], A[r]
                i = r
        l = i*2 + 1
        r = i*2 + 2

def build_heap(A):
    global last
    heap = []
    for i in A:
        heap.append(i)
        last += 1
        up_heapify(last-1, heap)
    return heap

def insert(ele, heap):
    global last
    if last < len(heap):
        heap[last] = ele
    else:
        heap.append(ele)
    up_heapify(last, heap)
    last += 1

def delete_min(A):
    global last
    res = A[0]
    last -= 1
    A[0] = A[last]
    A[last] = -1
    down_heapify(0, A)
    return res

A = [3,2,4,1,5,7,2]
h = []
global last
last = 0
for i in A:
    insert(i, h)
print(h)
ans = 0
while True:
    t = delete_min(h) + delete_min(h)
    ans += t
    print(h)
    if last == 0:
        break
    insert(t, h)
    print(h)




