/*
    Problem statemnt: Given a set of distinct positive integers, find the largest subset such that 
    every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.
*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    
    sort(A.begin(), A.end());

    vector<int> LDS(n+1, 1);
    LDS[0] = 1;

    vector<int> LDS_ARR(n+1);
    
    for(int i = 1; i < n; i++) LDS_ARR[i] = i;

    int lds_len = 1;
    int idx = 0;
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < i; j++){
            if(A[i-1] % A[j-1] == 0 || A[j-1] % A[i-1] == 0){
                if(LDS[j] + 1 > LDS[i]){
                    LDS[i] = LDS[j] +1; 
                    LDS_ARR[i] = j;
                }
            } 
        }
        if(lds_len < LDS[i]){
            lds_len = LDS[i];
            idx = i;
        }
    }

    vector<int> ans;

    while(LDS_ARR[idx] != idx){
        ans.emplace_back(A[idx-1]);
        idx = LDS_ARR[idx];
    }
        
    reverse(ans.begin(), ans.end());
    // return ans;
    for(auto x: ans) cout << x << " " ;
    return 0;
}
