from LinkedList import LinkedList

def solve(h):
    if not h.next:
        return 1
    if not h:
        return 0
    ans = 1
    pre, cur, nxt = None, h, h.next
    
    while nxt:
        cur.next = pre
        cur_len = 1
        h1 = pre
        h2 = nxt
        while h1 and h2:
            if h1.val == h2.val:
                cur_len += 2
                h1 = h1.next
                h2 = h2.next
            else:
                break
        ans = max(ans, cur_len)
        pre = cur
        cur = nxt
        nxt = nxt.next
    
    cur.next = pre
    pre = None
    nxt = cur.next

    while nxt:
        # print(cur.val, nxt.val)
        cur.next = pre
        if cur.val == nxt.val:
            cur_len = 2
            
            h1 = pre
            h2 = nxt.next
            while h1 and h2:
                if h1.val == h2.val:
                    cur_len += 2
                    h1 = h1.next
                    h2 = h2.next
                else:
                    break
            # print("this is for even", cur_len)
        ans = max(ans, cur_len)
        pre = cur
        cur = nxt
        nxt = nxt.next

    return ans


def main():
    l = LinkedList()
    l.add_node(1)
    l.add_node(2)
    l.add_node(5)
    l.add_node(2)
    l.add_node(1)
    l.add_node(1)
    l.add_node(2)
    l.add_node(2)
    l.add_node(1)
    l.add_node(1)
    l.add_node(2)
    l.add_node(5)
    # l.print_list()
    print(solve(l.head))
    # l.print_list()
if __name__ == "__main__":
    main()