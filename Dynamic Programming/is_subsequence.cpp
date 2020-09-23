#include <iostream>
#include <string>
#include <vector>
# include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string S, T;
    cin >> S >> T;
    
    int N = S.length();
    int M = T.length();

    vector<vector<bool>> check(N + 1);

    for(int i = 0; i < N + 1; i++) check[i] = vector<bool>(M + 1, false);
    
    for(int j = 0; j < N+1; j++) check[j][0] = true;
    
    check[0][0] = true;

    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < M + 1; j++){
            if(S[i-1] == T[j-1]) check[i][j] = check[i-1][j-1];
            else check[i][j] = check[i-1][j];
        }
    }
    // return check[N][M];
    for(int i = 0; i < N + 1; i++){
        for(int j = 0; j < M + 1; j++){
            cout << check[i][j] << " ";
        }
        cout << endl;
    }
    
    if(check[N][M]) cout << "Yes " << T << " is a subsequence of " << S << endl;
    else cout << T << " is a not a subsequence of " << S << endl;


    return 0;
}