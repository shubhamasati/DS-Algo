/*
    Problem Statement: Given a matrix with M rows and N columns (N x M). In each cell there’s a number of
    apples. You start from the upper-left corner of the matrix. You can go down or right one cell. You 
    need to arrive to the bottom-right corner. Then you need to go back to the upper-left cell by going 
    each step one cell left or up. Having arrived at this upper-left cell, you need to go again back to 
    the bottom-right cell.
    Find the maximum number of apples you can collect.
    When you pass through a cell – you collect all the apples left there.
*/

#include <bits/stdc++.h>
using namespace std;

// int find_max_path()

int main(int argc, char const *argv[])
{
    int n, m;
    
    string s;
    s = "a";
    s.append(string(1, 'b'));
    cout << s ;    
    // vector<vector<int>> A(n, vector<int>(m));

    // for(int i = 0; i < n; i++)
    //     for(int j = 0; j < m; j++) cin >> A[i][j];
    
    
    return 0;
}
