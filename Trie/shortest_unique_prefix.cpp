#include <bits/stdc++.h>
using namespace std;

struct Node{
    map<char, Node> children;
    bool isEnd = false;
    int words = 0;
};

void insert(Node *trie, string word){
    Node *temp = trie;
    
    for(auto ch: word){
        if(temp->children.find(ch) == temp->children.end()){
            temp->children.insert({ch, Node()});
        }
        temp->words++;
        temp = &temp->children[ch];
    }
    temp->isEnd = true;
}

string find(Node *trie, string word){
    Node *temp = trie;
    string ans;
    for(auto ch: word){
        ans += ch;
        temp = &temp->children[ch];
        if(temp->words == 1) break;
    }
    return ans;
}

int main(){

    string A[] = {"zebra", "dog", "duck", "dove"};

    Node trie = Node();
    
    for(auto s: A){
        insert(&trie, s);
    }
    vector<string> ans;
    for(auto s: A){
        ans.push_back(find(&trie, s));
    }
    
    for(auto c: ans) cout << c << " " ;
}