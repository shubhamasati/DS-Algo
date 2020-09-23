/* 
  given two arrays A and B of size n, you can swap A[i] and B[i], you need to sort
  both the arrays in minimum number of swaps

    A: 1 4 4 11
    B: 3 1 10 8

    output: 2
*/

#include <bits/stdc++.h>
using namespace std;
int count(vector<int> A, vector<int> B, int pos, bool is_last_swapped, vector<vector<int>> memo){
    //Base case
    if(pos == A.size()) return 0;

    // Check if alredy calculated
    if(memo[pos][is_last_swapped] != -1) return memo[pos][is_last_swapped];

    if(is_last_swapped){
        if(B[pos-1] < A[pos] && A[pos-1] < B[pos])
            memo[pos][is_last_swapped] = min(1 + count(A, B, pos+1, true, memo), count(A, B, pos+1, false, memo));
        else
            return INT_MAX - 1;
    }else{
        if(A[pos-1] < A[pos] && B[pos-1] < B[pos])
            memo[pos][is_last_swapped] = min(1 + count(A, B, pos+1, true, memo), count(A, B, pos+1, false, memo));
        else
            return INT_MAX - 1;
    }
    return memo[pos][is_last_swapped];
}
int main(){
    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> B(n);

    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];

    vector<vector<int>> memo(n, vector<int>(2, -1));
    cout << count(A, B, 0, false, memo) << endl;
    
    return 0;
}