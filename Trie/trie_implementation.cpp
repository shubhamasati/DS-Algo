#include <bits/stdc++.h>
using namespace std;

struct Node{
    map<char, Node> children;
    bool isEnd = false;
};

void insert(Node *trie, string word){
    Node *temp = trie;
    
    for(auto ch: word){
        if(temp->children.find(ch) == temp->children.end()){
            temp->children.insert({ch, Node()});
        }
        temp = &temp->children[ch];
    }
    temp->isEnd = true;
}

bool find(Node *trie, string word){
    Node *temp = trie;

    for(auto ch: word){
        if(temp->children.find(ch) == temp->children.end()) return false;
        temp = &temp->children[ch];
    }
    return temp->isEnd;
}

// bool delete_word(Node *trie, string word){
//     Node *temp = trie;  
//     if(find(trie, word)){

//     }
//     return false;   
// }



int main(){
    Node trie = Node();
    insert(&trie, "shubham");
    insert(&trie, "asati");
    insert(&trie, "surabhi");
    insert(&trie, "banjara");
    insert(&trie, "suman");

    cout << find(&trie, "shubham") << endl;
    cout << find(&trie, "shubh") << endl;
    cout << find(&trie, "aniket") << endl;
    cout << find(&trie, "surabhi") << endl;
    cout << find(&trie, "surabhiraj") << endl;

}