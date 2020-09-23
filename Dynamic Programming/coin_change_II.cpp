/*
    Problem Statement: You are given coins of different denominations and a total amount of money. 
    Write a function to compute the number of combinations that make up that amount. You may assume 
    that you have infinite number of each kind of coin.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){

    int size;
    cin >> size;

    vector<int> A(size);

    for(int i = 0; i < size; i++) cin >> A[i];

    int amt;
    cin >> amt;

    vector<vector<int>> ways(amt + 1, vector<int>(size+1, 0));


    for(int i = 0; i < size + 1; i++) ways[0][i] = 1;
    
    for(int i = 1; i < amt + 1; i++){
        for(int j = 1; j < size + 1; j++){
            if(A[j-1] <= i) ways[i][j] = ways[i - A[j-1]][j] + ways[i][j-1];
            else ways[i][j] = ways[i][j-1];
        }
    }
    cout << ways[amt][size] << endl;
}