/*
We want to make a custom contacts finder applications as part of our college project. The application must
 perform two types of operations:
Type 1: Add name B[i] ,denoted by 0 in vector A where B[i] is a string in vector B denoting a contact name. 
This must store B[i] as a new contact in the application.
Type 2: Find partial for B[i] ,denoted by 1 in vector A where B[i] is a string in vector B denoting a partial 
name to search the application for. It must count the number of contacts starting with B[i].
You have been given sequential add and find operations. You need to perform each operation in order.
And return as an array of integers, answers for each query of type 2(denoted by 1 in A) .

problem link:
https://www.scaler.com/academy/mentee-dashboard/classroom/remedial-tries-b18cfb18-92e1-48c7-aa61-2a3ecf495604/#assignment

*/
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

int find(Node *trie, string word){
    Node *temp = trie;

    for(auto ch: word){
        if(temp->children.find(ch) == temp->children.end()) return 0;
        temp = &temp->children[ch];
    }
    return temp->words;
}

int main(){
    int A[] = {0, 0, 1, 1};
    string B[] = {"hack", "hacker", "hac", "hak"};

    int n = 4;

    Node trie = Node();
    vector<int> ans;

    for(int i = 0; i < n; i++){
        if(A[i] == 0) insert(&trie, B[i]);
        if(A[i] == 1) ans.push_back(find(&trie, B[i]));
    }
    
    for(auto i:ans) cout << i << " ";
}

