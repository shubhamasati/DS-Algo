/*
for k in range(N):
            for i in range(N):
                for j in range(N):
                    if A[i][j] == -1:
                        if A[i][k] != -1 and A[k][j] != -1:
                            A[i][j] = A[i][k] + A[k][j];
                    else:
                        if A[i][k] != -1 and A[k][j] != -1:
                            A[i][j] = min(A[i][j], A[i][k] + A[k][j]);


*/


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

#define INF 9999999

int main(int argc, char const *argv[])
{
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> D(B);
    vector<int> E(B);
    vector<int> F(B);
    vector<int> G(C);
    vector<int> H(C);

    

    for(int i = 0; i < B; i++) cin >> D[i];
    for(int i = 0; i < B; i++) cin >> E[i];
    for(int i = 0; i < B; i++) cin >> F[i];
    for(int i = 0; i < C; i++) cin >> G[i];
    for(int i = 0; i < C; i++) cin >> H[i];
    

    vector<vector<int>> dis(A, vector<int>(A, INF));
    for(int i = 0; i < B; i++){
        dis[E[i]-1][D[i]-1] = F[i];
        dis[D[i]-1][E[i]-1] = F[i];
    }
    
    for(int i = 0; i < A; i++) dis[i][i] = 0;

    for(int k = 0; k < A; k++){
        for(int i = 0; i < A; i++){
            for(int j = 0; j < A; j++){
                // if(dis[i][j] == -1){
                //     if(dis[i][k] != -1 && dis[k][j] != -1){
                //         dis[i][j] = dis[i][k] + dis[k][j];
                //     }
                // }else{
                //     if(dis[i][k] != -1 && dis[k][j] != -1){
                //         dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                //     }
                // }
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    
    for(int i = 0; i < C; i++){
        cout << dis[G[i] - 1][H[i] - 1]<< " ";
    }
    cout << endl;
    
    return 0;
}

/*

// INPUT I

4
6
2
1 2 3 2 4 3
2 3 4 4 1 1
4 1 1 1 1 1
1 1
2 3

OUTPUT [2, 1]

// INPUT II

3
3
2
1 2 1
2 3 3
3 1 1
2 1
3 2

// INPUT III

15
18
29
11 2 2 6 2 8 9 3 14 15 4 14 8 7 8 6 2 12 
2 1 1 2 1 1 7 3 2 13 2 1 6 1 7 1 2 10 
8337 6651 29 7765 3428 5213 6431 2864 3137 4024 8169 5013 7375 3786 4326 6415 8982 6864 
6 2 1 15 12 2 14 10 13 15 15 4 8 7 9 4 15 13 12 5 2 10 1 11 14 7 3 13 12 
5 2 15 13 6 2 8 6 3 13 15 3 1 1 4 4 5 8 1 3 1 10 15 9 2 1 1 10 2 


*/