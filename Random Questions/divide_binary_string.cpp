/*
    Problem statement: given one binary string, you have to tell if this string can be divide into
                       3 parts, so that the decimal value of each part is equal.
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> S){
    
    int N = (int)S.size();
    
    int j = N-1;
    int trailing_zeros = 0;
    while(j > -1 and S[j--] == 0) trailing_zeros++;
    
    j = -1;
    int ones = 0;
    while(j++ < N){
        if(S[j] == 1) ones++;
    }
    
    vector<int> not_div(2, -1);
    vector<int> ans;

    if(ones == 0){
        ans.push_back(0);
        ans.push_back(N - 1);
        return ans;
    }
    cout << ones << endl;
    if(ones % 3 == 0){
        int one_req = ones/3;
        j = 0;
        while(j < N){
            if(S[j] == 1) one_req--;
            if(one_req == 0){
                j++;
                int t = trailing_zeros;
                while(t > 0 && j < N && S[j] == 0){
                    t--;
                    j++;
                }
                if(t != 0) return not_div;
                ans.push_back(j-1);
                j--;
                one_req = ones/3;
            }
            j++;
        }
        if(ans.size() > 2) ans.pop_back();
        
        for(auto x: ans) cout << x << " ";
        cout << endl;
        int len = 0;
        len = min(ans[0] - 0, ans[1] - ans[0]);
        len = min(len, N - ans[1]);
        ans[1]++;
        // for(auto i: ans) cout << i << endl;
        for(int i = 1; i <= len; i++){
            if(S[N - i] != S[ans[1] - len] && S[ans[1] - len] != S[ans[0] + 1 - len]) return not_div;
        }
        return ans;
    }
    return not_div;
}

int main(){
    
    vector<int> A = {0,1,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0};
    for(auto x: solve(A)) cout << "THIS " << x << " ";
    
   return 0;
}