from Node import Node

class LinkedList:
    
    def __init__(self):
        self.head = None
        self.tail = None
        self.__len = 0
    
    def add_at_start(self, val):
        new_node = Node(val)
        new_node.next = self.head
        self.head = new_node
        self.__len += 1
    
    def add_node(self, val, pos = -1):
        new_node = Node(val)
        t = self.head
        if pos != -1:
            if pos == 1:
                self.add_at_start(val)
            else:
                count = 1
                while t and count < pos-1:
                    t = t.next
                    count += 1
                if not t:
                    print("Can not insert at given position.")
                    return
                nxt = t.next
                t.next = new_node
                new_node.next = nxt
                self.__len += 1
        else:
            t = self.head
            if not t:
                self.add_at_start(val)
            else:
                while t.next:
                    t = t.next
                t.next = new_node
                self.__len += 1

    def delete_node(self, pos = -1):
        if not self.head:
            print('List is empty!')
            return
        pre = None
        cur = self.head
        if pos != -1:
            count = 1
            while cur and count < pos:
                pre = cur
                cur = cur.next
                count += 1
            if not cur:
                print("Can not delete the element at position out of list!")
                return
            if not pre:
                self.head = cur.next
            else:
                pre.next = cur.next
            self.__len -= 1
        else:
            while cur.next:
                pre = cur
                cur = cur.next
            if pre:
                pre.next = cur.next
            else:
                self.head = cur.next
            self.__len -= 1

            


    def print_list(self):
        if not self.head:
            print("Current length of the linked list is: ", self.__len)
            return
        t = self.head
        while t.next:
            print(t.val, end = ' -> ')
            t = t.next
        print(t.val)
        print("Current length of the linked list is: ", self.__len)
    
    def reverse_list(start = None, end = None):
        pass

def main():
    l = LinkedList()
    l.add_node(5)
    l.add_node(3)
    l.add_node(4,pos = 2)
    l.print_list()
    l.delete_node(pos = 2)
    l.print_list()
    l.delete_node()
    l.print_list()
    l.add_node(1)
    l.add_node(7, pos = 1)
    l.print_list()

    


if __name__ == "__main__":
    main()