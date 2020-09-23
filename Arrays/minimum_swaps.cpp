#include <bits/stdc++.h>
using namespace std;

int minimumSwaps(vector<int> arr) {
    int ans = 0;
    int n = arr.size();

    vector<bool> vis(n, false);
    // for(int i = 0; i < n; i++) vis[n] = false;

    for(int i = 0; i < n; i++){
        if(arr[i] - 1 == i || vis[i]){
            vis[i] = true;
            continue;
        } 
        cout << " here " << endl;
        int cycle = 0;
        int j = i;
        while(!vis[j]){
            // cout << " here " << endl;
            vis[j] = true;
            cycle++;
            j = arr[j] - 1;
        }
        ans += (cycle - 1);
    }
    return ans;
}

int main(int argc, char const *argv[])
{   
    int n;
    cin >> n;
    vector<int> A(n);

    for(int i = 0 ; i < n; i++) cin >> A[i];

    cout << minimumSwaps(A) << endl;

    return 0;
}
