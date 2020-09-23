/*
Given an array of integers A of size N.

A triplet (i, j, k) is valid if a[i] < a[j] < a[k] and i < j < k.

Value of a valid triplet = a[i] + a[j] * a[k].

Return maximum value among values of all valid triplets, If there is no valid triplet in the entire array return -1.

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> max_arr(n);

    max_arr[n-1] = arr[n-1];
    for(int i = n - 2; i > -1; i--){
        max_arr[i] = max(max_arr[i+1], arr[i]);
    }
    
    // Using Binary search in left part to find max element less than the arr[i](currebt_element)
    // using suffix max_array to find max element in right part
    int ans = -1;
    set<int> s;
    s.insert(arr[0]);
    for(int i = 1; i < n - 1; i++){
        auto left = --(s.lower_bound(arr[i]));
        int right = max_arr[i+1];
        if(*left < arr[i] && arr[i] < right) ans = max(ans, *left + (arr[i] * right));
        s.insert(arr[i]);
    }
    cout << ans << endl;
}
/*
55 92 88 24 49 87 9 52 72 96 

10
61 6 97 29 17 74 51 6 22 98
*/