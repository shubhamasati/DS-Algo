#include <bits/stdc++.h>
using namespace std;

#define N 1000000
int tree[N];

int build(int index, int l, int h, vector<int> arr){
    if(l == h){
        tree[index] = arr[l];
        return tree[index];
    }
    int mid = l + (h - l) >> 1;
    int l_index = index * 2 + 1;
    int r_index = index * 2 + 2;

    build(l_index, l, mid, arr);
    build(r_index, mid + 1, h, arr);

    tree[index] = tree[l_index] + tree[r_index];
    return tree[index];
}

void update(int index, int l, int h, int u_idx){
    if(l == h){
        tree[index] ^= 1;
        return;
    }
    int mid = l + (h - l) >> 1;
    if(u_idx <= mid){
        update(index*2 + 1, l, mid, u_idx);
    }else{
        update(index*2 + 2, mid + 1, h, u_idx);
    }
    tree[index] = tree[index*2 + 1] + tree[index*2 + 2];    
}

int query(int index, int s, int e, int l, int r){
    if(l > s && r < e) return 0;
    else if(l <= s && e <= r) return tree[index];
    else{
        int mid = s + (e - r) >> 1;
        return query(index*2 + 1, s, mid, l, r) + query(index*2 + 2, mid+1, e, l, r);
    }
    
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    vector<vector<int>> B = {{0, 1, 3}, {1, 1, 2}, {0, 0, 4}, {1, 3, 4}};
    for(auto t: B){
        if(t[0] == 0){

        }
    }
    return 0;
}