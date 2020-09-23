#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();

    vector<vector<int>> is_sub(n+1, vector<int>(n+1, 0));

    // substring of length 1 is always Palindrome
    for(int i = 1; i < n+1; i++) is_sub[i][i] = 1;
    // Palindrome of length 2
    for(int i = 1; i < n; i++) if(s[i-1] == s[i]) is_sub[i][i+1] = 1;


    int j;
    for(int l = 3; l < n+1; l++){
        for(int i = 1; i < n - l + 2; i++){
            j = i + l  - 1;
            // checking for substring having starting point i and ending point j
            if(j < n + 1) is_sub[i][j] = is_sub[i+1][j-1] && (s[i-1] == s[j-1]);
        }
    }
    
    // Calculating prefix sum
    for(int i = 0; i < n+1; i++)
        for(int j = 1; j < n+1; j++) is_sub[i][j] += is_sub[i][j-1];
    
    for(int j = 0; j < n+1; j++)
        for(int i = 1; i < n+1; i++) is_sub[i][j] += is_sub[i-1][j];
    

    int q, x, y;
    
    // queries
    int ans;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        ans = is_sub[y][y] + is_sub[x-1][x-1] - is_sub[x-1][y] - is_sub[y][x-1];
        // printf("%d \n",ans);
        cout << ans << '\n';
    }

    return 0;
}
