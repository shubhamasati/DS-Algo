/*
    Problem statement: given an unsorted array, find longest increasing subsequence.
*/

/*
    Goal: finding longest increasing subsequence for the given array;

    DP state: LIS[i] = length of longest increasing subsequence for index (1 to ith) of array.

    Base Cases:
        LIS[0] = 0;
        LIS[1] = 1;

    Recurrence Relation: LIS[i] = max(LIS[j] for j in range(1, i-1)) + 1; where A[j] < A[i];

*/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    vector<int> LIS(n+1, 1);
    
    LIS[0] = 0;
    int ans = 1;

    for(int i = 2; i < n+1; i++){
        for(int j = 1; j < i; j++){
            if(A[j-1] < A[i-1]) LIS[i] = max(LIS[i], LIS[j] + 1);
        }
        ans = max(ans, LIS[i]);
    }
    cout << ans << endl;

    return 0;
}
