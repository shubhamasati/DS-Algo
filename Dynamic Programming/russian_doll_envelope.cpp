/*
    Problem Statement: You have a number of envelopes with widths and heights given as a pair of 
    integers (w, h). One envelope can fit into another if and only if both the width and height 
    of one envelope is greater than the width and height of the other envelope.
    What is the maximum number of envelopes can you Russian doll? (put one inside other)
*/

/*
    This problem can be solved using Longest Increasing subsequence.
*/

#include <bits/stdc++.h>
using namespace std;

bool com(vector<int> a, vector<int> b){
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<vector<int>> A(n, vector<int>(2));;
    for(int i = 0; i < n; i++) cin >> A[i][0] >> A[i][1];
    
    sort(A.begin(), A.end(), com);
    for(auto x: A) cout << x[0] << " " << x[1] << endl;
    int last_w = A[0][0], last_h = A[0][1], ans = 1;
    for(int i = 1; i < n; i++){
        if(A[i][0] > last_w && last_h < A[i][1]){
            last_w = A[i][0];
            last_h = A[i][1];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
// 2 100 3 200 4 300 5 500 5 400 5 250 6 370 6 360 7 380