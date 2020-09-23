#include <bits/stdc++.h>
using namespace std;

int main(){
    int cap, n;
    cin >> n;

    vector<int> filing(n);
    vector<int> cost(n);

    for(int i = 0; i < n; i++) cin >> filing[i];
    for(int i = 0; i < n; i++) cin >> cost[i];
    
    cin >> cap;

    vector<int> dp(cap + 1, INT_MAX/2);

    dp[0] = 0;
    for(int i = 1; i < cap + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(filing[j-1] <= i){
                dp[i] = min(cost[j-1] + dp[i - filing[j-1]] , dp[i]);
            }
        }
    }
    for(int i = 1; i < cap + 1; i++) cout << dp[i] << endl;


    
    return 0;
}