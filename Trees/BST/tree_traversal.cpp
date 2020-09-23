#include <bits/stdc++.h>
using namespace std;

struct Node{
  struct Node *left;
  struct Node *right;
  int val;
};

Node* insert(Node *root, int val){
    if(root == nullptr){
       struct Node *tempNode = (struct Node*) malloc(sizeof(struct Node));
       tempNode->val = val;
       return tempNode;
    }
    if(val <= root->val) root->left = insert(root->left, val);
    if(val > root->val) root->right = insert(root->right, val);
    return root;
}

void traverse(Node *root){
    if(root == nullptr) return;
    if(root->left == nullptr && root->right == nullptr) cout << root->val << endl;
    traverse(root->right);
    traverse(root->left);
}

int main() {
    int n;
    cin >> n;
    int x;
    Node *root = nullptr;
    
    for(int i = 0; i < n; i++){
        cin >> x;
        root = insert(root, x);
    }
    traverse(root);

}