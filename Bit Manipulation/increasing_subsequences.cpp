/*
    Given an integer array, your task is to find all the different possible increasing subsequences of 
    the given array, and the length of an increasing subsequence should be at least 2.

    Constraints:
       1. The length of the given array will not exceed 15.
       2. The range of integer in the given array is [-100,100].
       3. The given array may contain duplicates, and two equal integers should also be considered as 
          a special case of increasing sequence.
*/

#include <bits/stdc++.h>
using namespace std;

bool check_increasing(vector<int> A){
    int pre = A[0];
    for(int i = 1; i < A.size(); i++){
        if(pre > A[i]) return false;
        pre = A[i];
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    
    
    set<vector<int>> ans;
    for(int i = 1; i < 1 << n; i++){
        vector<int> temp;
        for(int j = 0; j < n; j++){
            if(i >> j & 1) temp.emplace_back(A[j]);
        }
        if( temp.size() > 1 && check_increasing(temp)) ans.insert(temp);
    }
    // return ans;
    return 0;
}