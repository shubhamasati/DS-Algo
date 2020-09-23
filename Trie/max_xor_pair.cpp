
#include <bits/stdc++.h>
using namespace std;

struct node {
    struct node *vals[2];
};

class Trie {
    private: 
        node *root = get_node();
    public:
        struct node *get_node(void) {
            struct node *new_node = new node();
            new_node->vals[0] = nullptr;
            new_node->vals[1] = nullptr;
        }

        void insert(int n) {
            node *temp = root;
            for (int i = 31; i > -1; i--) {
                
                int cur_bit = n >> i & 1 ;
                
                if (cur_bit == 0 && temp->vals[cur_bit] == nullptr) {
                    temp->vals[cur_bit] = get_node();
                } else if (cur_bit == 1 && temp->vals[cur_bit] == nullptr) {
                    temp->vals[cur_bit] = get_node();
                }

                temp = temp->vals[cur_bit];
            }
        }

        bool find(int n){
            node *temp = root;
            for (int i = 31; i > -1; i--) {
                
                int cur_bit = n >> i & 1 ;
                
                if ((cur_bit == 0 && temp->vals[cur_bit] == nullptr) || (cur_bit == 1 && temp->vals[cur_bit] == nullptr)) {
                    return false;
                }
                temp = temp->vals[cur_bit];
            }
            return true;
        }
};

int main() {

    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8};

    Trie t = Trie();
    
    for (auto x: A) t.insert(x);

    cout << t.find(9) << endl;
    cout << t.find(4) << endl;
    cout << t.find(10) << endl;
    cout << t.find(3) << endl;
    cout << t.find(8) << endl;



    return 0;
}