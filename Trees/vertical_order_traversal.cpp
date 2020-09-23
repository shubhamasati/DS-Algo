#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    //TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> vertical_order(TreeNode *root) {
    
    // Vector for storing the output
    vector<vector<int>> ans;

    // if tree is empty
    if (root == nullptr) return ans;
    
    map<int, vector<int>> m;
    queue<pair<TreeNode*, int>> q;
    
    // Level order traversal

    q.push({root, 0});

    while (!q.empty()) {
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        m[temp.second].push_back(temp.first->val);

        if (temp.first->left != NULL) {
            q.push({temp.first->left, temp.second - 1});
        }
        if (temp.first->right != NULL) {
            q.push({temp.first->right, temp.second + 1});
        }
    }

    // Iterating over the map to get the result of each layer
    map<int, vector<int>>::iterator itr = m.begin();
    while (itr != m.end()) {
        ans.push_back(itr->second);
    }
    return ans;
}


int main() {
    
    TreeNode *root;

    vector<vector<int>> a = vertical_order(root);
    
    for(auto t: a){
        for(int i = 0; i < t.size(); i++) {
            cout << t[i] << " ";
        }
        cout << endl;
    }

    return 0;
}