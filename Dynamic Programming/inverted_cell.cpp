/*
Given matrix n*m. We assume that the matrix rows are numbered from 1 to n from top to bottom, and the 
matrix columns are numbered from 1 to m from left to right. Then the cell of the field at the intersection
 of the x-th row and the y-th column has coordinates (x, y).

Every cell is empty or blocked. For every cell (x,y) determine if we change the state of the cell (x,y)
(empty to blocked or blocked to empty), is it possible to reach cell (n,m) from (1,1) and going only down 
and right . 

Input format

First line contains two space-seperated numbers  n, m - number of rows and columns.
Next n lines contains m symbols. If symbol on (x, y) is '#', cell is blocked, else if symbol is '.', cell is 
empty.

Output format

Print  n lines, where every line contains m numbers. Print 0 if it is impossible to reach , 
otherwise print 1.

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    string A[n];
    for(int i = 0; i < n; i++) cin >> A[i];

    vector<vector<bool>> fromstart(n, vector<bool>(m, -1));

    if(A[0][0] == '.') fromstart[0][0] = true;
    else fromstart[0][0] = false;

    for(int i = 1; i < n; i++){
        if(A[i][0] == '#') fromstart[i][0] = false;
        else fromstart[i][0] = fromstart[i-1][0];
    }

    for(int i = 1; i < m; i++){
        if(A[0][i] == '#') fromstart[0][i] = false;
        else fromstart[0][i] = fromstart[0][i-1];
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            fromstart[i][j] = A[i][j] == '.' && (fromstart[i-1][j] || fromstart[i][j-1]);
        }
    }
    
    vector<vector<bool>> start_to_end(n, vector<bool>(m, false));
    start_to_end[n-1][m-1] = A[n-1][m-1] == '.' && fromstart[n-1][m-1];

    for(int i = n - 2; i > -1; i--){
        if(A[i][m-1] == '.') start_to_end[i][m-1] = start_to_end[i+1][m-1] && fromstart[i][m-1];
        else start_to_end[i][m-1] = false;
    }

    for(int i = m - 2; i > -1; i--){
        if(A[n-1][i] == '.') start_to_end[n-1][i] = start_to_end[n-1][i+1] && fromstart[n-1][i];
        else start_to_end[n-1][i] = false;
    }

    for(int i = n - 2; i > -1; i--){
        for(int j = m - 2; j > -1; j--){
            start_to_end[i][j] = (start_to_end[i+1][j] || start_to_end[i][j+1]) && fromstart[i][j];
        }
    }

    vector<vector<int>> ans(n, vector<int>(m));
    
    if(A[n-1][m-1] == '#') ans[n-1][m-1] = start_to_end[n-2][m-1] || start_to_end[n-1][m-2];
    else ans[n-1][m-1] = 0;

    for(int i = n - 2; i > -1; i--){
        if(A[i][m-1] == '.') ans[i][m-1] = start_to_end[i+1][m-2];
        else ans[i][m-1] = start_to_end[i-1][m-1] || start_to_end[i][m-2];
    }

    for(int i = m - 2; i > -1; i--){
        if(A[n-1][i] == '.') ans[n-1][i] = start_to_end[n-2][i+1];
        else ans[n-1][i] = start_to_end[n-2][i] || start_to_end[n-1][i-1];
    }

    for(int i = n - 2; i > 0; i--){
        for(int j = m - 2; j > 0; j--){
            if(A[i][j] == '#') ans[i][j] = start_to_end[i-1][j] || start_to_end[i][j-1];
            else ans[i][j] = start_to_end[i-1][j-1] || start_to_end[i+1][j+1];
        }
    }

    for(int i = 1; i < n; i++){
        if(A[i][0] == '#') ans[i][0] = start_to_end[i-1][0];
        else ans[i][0] = start_to_end[i-1][1]; 
    }
    for(int i = 1; i < m;  i++){
        if(A[0][i] == '#') ans[0][i] = start_to_end[0][i-1];
        else ans[0][i] = start_to_end[1][i-1];
    }
    
    if(A[0][0] == '.') ans[0][0] = 0;
    else ans[0][0] = start_to_end[0][0];
    


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}