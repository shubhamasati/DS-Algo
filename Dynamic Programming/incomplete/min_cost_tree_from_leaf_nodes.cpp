/*
    Problem Statement: Given an array arr of positive integers, consider all binary trees such that:

    -> Each node has either 0 or 2 children;
    -> The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  
    (Recall that a node is a leaf if and only if it has 0 children.)
    -> The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
 
Among all possible binary trees considered, return the smallest possible sum of the values of each
non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

Input: arr = [6,2,4]
Output: 32
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i <N; i++) cin >> A[i];


    vector<vector<int>> cost(N, vector<int>(N, INT32_MAX));

    for(int i = 0; i < N; i++) cost[i][i] = 0;

    
    for(int l = 1; l < N; l++){
        for(int i = N-2; i > -1; i--){
            int j = min(i + l, N-1);   
            for(int k = i; k < j; k++){
                auto first = max_element(A.begin() + i, A.begin() + k);
                auto second = max_element(A.begin() + k + 1, A.begin() + j + 1);
                // cout << *first << " " << *second << endl;
                cost[i][j] = min(cost[i][j], (*first)*(*second) + cost[i][k] + cost[k+1][j]);
                cout << i << " " << j << " " << cost[i][j] << endl;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}