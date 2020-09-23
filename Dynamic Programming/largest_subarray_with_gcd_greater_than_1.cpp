#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

// calculating seive of smallest prime factor
vector<int> get_spf(int N){
    int sqrt_n = (int)sqrt(N);
    vector<int> spf(N+1);

    spf[1] = 1;
    spf[2] = 2;

    for(int i = 3; i < N+1; i++) spf[i] = i;
    for(int i = 4; i < N+1; i += 2) spf[i] = 2;
    
    for(int i = 3; i <= sqrt_n; i += 2){
        if(spf[i] == i){
            for(int j = i * i; j < N+1; j += i) spf[j] = i;
        }
    }
    return spf;
}

int main(){
    // vector<int> A = {4, 9, 6, 8, 25, 2, 6, 6, 4, 5, 3};
    vector<int> A = {3, 25, 9, 8, 6, 8, 12, 5, 3, 3, 9, 3, 25, 8, 8, 9, 12, 5};

    int N = A.size();

    vector<int> spf  = get_spf(*max_element(A.begin(), A.end()));
    int M;
    for(int i = 2; i < spf.size(); i++) if(spf[i] == i) M++;

    map<int, vector<int>> indexes;

    for(int i = 0; i < N; i++){
        int x = A[i];
        while(x != 1){
            if(!indexes[spf[x]].empty()){
              if(indexes[spf[x]].back() != i)
                indexes[spf[x]].push_back(i);
            }
            else indexes[spf[x]].push_back(i);
            x /= spf[x];
        }
    }

    // for(auto i: indexes[3]) cout << i<< " ";
    // cout << endl;
    int ans = -1, i, j;
    for(auto i = indexes.begin(); i != indexes.end(); i++){
        int l = 0;
        
        auto temp = i->second;
        int m = temp.size();
        for(j = 1; j < m; j++){
            if(temp[j-1] + 1 != temp[j]){
                ans = max(ans, j - l);
                l = j;
            }
        }
        ans = max(ans, j - l);
    }

    cout << ans << endl;

    // int ans = -1;
    // int j;
    // for(int i = 0; i < M; i++){
    //     int l = 0;
    //     for(j = 1; j < dp[i].size(); j++){
    //         if(dp[i][j-1] + 1 != dp[i][j]){
    //             ans = max(ans, j - l);
    //             l = j;
    //         }
    //     }
    //     ans = max(ans, j - l);
    // }

}