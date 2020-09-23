/*

*/ 

#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E, vector<int> &F) {
    unordered_map<int, vector<int>> tree;
    
    for(int i = 0; i < A - 1; i++){
        tree[B[i]].push_back(C[i]);
        tree[C[i]].push_back(B[i]);
    }
    
    
    int height = 0;
    vector<multiset<int>> level(A, multiset<int>());
    vector<bool> vis(A+1, false);
    
    queue<pair<int, int>> Q;
    Q.push({1, 0});
    vis[1] = true;
    
    while(!Q.empty()){
        pair<int, int> p = Q.front();
        Q.pop();
        
        level[p.second].insert(D[p.first - 1]);
        height = max(height, p.second+1);
        
        for(auto x: tree[p.first]){
            if(!vis[x]){
                Q.push({x, p.second+1});
                vis[x] = true;
            } 
        }
    }
    vector<int> ans;
    for(int i = 0; i < E.size(); i++){
        int l = E[i] % height;
        auto ptr = level[l].lower_bound(F[i]);
        int val = *ptr;
        auto ptr_cp = ptr;
        if(*(++ptr_cp) == F[i]) ans.push_back(F[i]);
        else if(ptr == level[l].end()) ans.push_back(-1);
        else ans.push_back(val);
    }
    return ans;
}

int main(){
    int A = 5;
    vector<int> B = {5,2,4,4};
    vector<int> C = {1, 4, 3, 1};
    vector<int> D = {7, 38, 27, 37, 1};
    vector<int> E = {1, 10, 2};
    vector<int> F = {32, 18, 40};
    vector<int> ans = solve(A,B, C, D, E, F);
    for(auto x: ans) cout << x << " ";
    return 0;
}