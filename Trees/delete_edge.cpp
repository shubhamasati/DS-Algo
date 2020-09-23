

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<int, TreeNode*> m;
void delete_node(TreeNode *root, TreeNode *parent){
    if(root == nullptr) return;
    if(m.find(root->val) != m.end()){
        TreeNode *pre = m[root->val];
        if(parent->val > pre->val){
            if(parent->left != nullptr && parent->left->val == root->val) parent->left = nullptr;
            if(parent->right != nullptr && parent->right->val == root->val) parent->right = nullptr;
        }else{
            if(pre->left != nullptr && pre->left->val == root->val) pre->left = nullptr;
            if(pre->right != nullptr && pre->right->val == root->val) pre->right = nullptr;
        }
        return;
    }
    m.insert({root->val, parent});
    delete_node(root->left, root);
    delete_node(root->right, root);
}

TreeNode* solve(TreeNode* A) {
    delete_node(A, nullptr);
    return A;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    solve(root);
    return 0;
}