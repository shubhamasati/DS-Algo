#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    struct node *next;
};

node *get_node(int n) {
    
    node *new_node = new node();
    new_node->val = n;
    new_node->next = NULL;
    return new_node;
}

node *insert_at_last(node *head, int v){
    if (head == NULL) head = get_node(v);
    else {
        node *temp = head;
        // O(n)
        while (temp->next != NULL) temp = temp->next;
        
        temp->next = get_node(v);
    }
    return head;
}

// O(1)
node *insert_at_begin(node *head, int v) {
    if (head == NULL) {
        head = get_node(v);
    }
    else {
        node *temp = head;
        head = get_node(v);
        head->next = temp;
    }
    return head;
}

node *delete_at_begin(node *head) {
    if (head == NULL) {
        cout << "list is empty" << endl;
        return head;
    }
    else {
        node *temp = head;
        head = head->next;
        delete(temp);
        return head;
    }
}

node *delete_at_last(node *head) {
    if (head == NULL) {
        cout << "list is empty" << endl;
        return head;
    }
    else if (head->next == NULL) {
        head = head->next;
        return head;
    }
    else {
        node *temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        temp->next = NULL;
        return head;
    }
}


void print_list(node *head) {
    node *temp = head;
    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    
    

    node *head = NULL;
    
    head = delete_at_last(head); //-1
    head = insert_at_begin(head, 1); // 1
    print_list(head);
    head = insert_at_last(head, 3); // 1, 3
    print_list(head);
    head = insert_at_begin(head, 2); // 2, 1, 3
    print_list(head);
    head = delete_at_begin(head);
    print_list(head);
}
