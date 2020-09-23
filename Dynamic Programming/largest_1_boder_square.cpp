#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int largest1BorderedSquare(vector<vector<int>>& grid) {
    int N, M;
    N = grid.size();
    M = grid[0].size();
    
    vector<vector<int>> row(N, vector<int>(M, 0));
    vector<vector<int>> col(N, vector<int>(M, 0));
    int ans = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(grid[i][j] == 1){
                ans = 1;
                row[i][j] = 1;
                col[i][j] = 1;
                if(j-1 > -1) row[i][j] = row[i][j-1] + 1;
                if(i-1 > -1) col[i][j] = col[i-1][j] + 1;
            }
        }
    }
    
    if(ans == 0) return 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(grid[i][j] == 1){
                int cur_len = min(row[i][j], col[i][j]);
                if(cur_len > ans){
                    for(int k = ans; k <= cur_len; k++){
                        if(-1 < (j-k+1) && -1 < (i-k+1) && row[i-k+1][j] >= k && col[i][j-k+1] >= k)
                            ans = k;
                    }
                }
            }
        }
    }
    return ans*ans;  
}

int main(){

    vector<vector<int>> in = {
        {1,1,1,1,1},
        {1,0,1,0,1},
        {1,0,1,1,1},
        {1,0,0,1,1},
        {1,1,1,1,1}
    };
    cout << largest1BorderedSquare(in) << endl;
}