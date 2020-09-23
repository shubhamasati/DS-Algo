#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string s = "bbbab";
    int n = s.length();

    vector<vector<int>> LPS(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < n+1; i++) LPS[i][i] = 1;
    for(int i = 1; i < n; i++) if(s[i-1] == s[i]) LPS[i][i+1] = 2;


    for(int l = 3; l < n+1; l++){
        for(int i = 1; i < n - l + 2; i++){
            int j = i + l - 1;
            if(s[i-1] == s[j-1]) LPS[i][j] = LPS[i+1][j-1] + 2;
            else LPS[i][j] = max(LPS[i+1][j], LPS[i][j-1]); 
        }
    }
    cout << LPS[1][n] << endl;
    return 0;
}
