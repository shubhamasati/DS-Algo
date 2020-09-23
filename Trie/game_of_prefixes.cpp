/*
    Two persons are playing a word game where players alternate appending letters to a word. The person who 
    spells out a word, or creates a prefix for which there is no continuation possible, loses.
Given a dictionary of words denoted by string array A, determine the letters the first player should start 
with, such that with the optimal play they cannot lose.

NOTE: If no letter satisfies the above condition, return a character array with only character '0'.

*/
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

bool find(Node *trie, bool turn){
    cout << trie->isEnd << " " << turn << endl;
    if(turn && trie->isEnd && trie->children.size() == 0) return false;
    if(!turn && trie->isEnd && trie->children.size() == 0) return true;

    Node *temp = trie;
    bool result;
    map<char, Node>::iterator itr = temp->children.begin();
    if(turn){
        result = true;
        while(itr != temp->children.end()){
            result = result & find(&itr->second, !turn);
            itr++;
        }
    }
    else{
        result = false; 
        while(itr != temp->children.end()){
           result = result | find(&itr->second, !turn);
           itr++;
        }
    }
    return result;
}


int main(){
    string arr[] = {"gv", "g", "gy"};

    Node trie = Node();
    for(auto s: arr){
        insert(&trie, s);
    }
    
    vector<char> ans;
    map<char, Node>::iterator itr = trie.children.begin();
    while(itr != trie.children.end()){
        
        if(find(&itr->second, true)) ans.push_back(itr->first);
        itr++;
    }


    for(auto c: ans){
        cout << c << " ";
    }

    return 0;
}