#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int find(int a, vector<int> parent){
    while(parent[a] != a) a = parent[a];
    return a;
}

void union_dsu(int a, int b, vector<int>& size, vector<int>& parent, vector<int>&strength){
    int a_par = find(a, parent);
    int b_par = find(b, parent);

    if(a_par == b_par) return;

    int st = strength[a_par] + strength[b_par];
        strength[a_par] = st;
        strength[b_par] = st;

    if(size[a_par] < size[b_par]){
        size[b_par] += size[a_par];
        parent[a_par] = b_par;
        
    } else{
        size[a_par] += size[b_par];
        parent[b_par] = a_par;
    }
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int M;
    cin >> M;
    vector<vector<int>> B(M, vector<int>(2, 0));
    for(int i = 0; i < M; i++) cin >> B[i][0] >> B[i][1];

    int D;
    cin >> D;

    vector<int> parent(N);
    for(int i = 0; i < N; i++) parent[i] = i;

    vector<int> size(N, 1);

    for(vector<int> a: B){
        union_dsu(a[0]-1, a[1]-1, size, parent, A);
    }
    set<int> temp;
    int ans = 0;
    for(int i = 0; i <N; i++){
        int i_par = find(i, parent);
        if(temp.find(i_par) == temp.end()){
            temp.insert(i_par);
            if(A[i_par] >= D) ans++;
        }
    }
    // cout << parent << endl;
    cout << ans << endl;
    return 0;
}

/*
7
1 6 7 2 9 4 5
4
1 2
2 3
5 6
6 7
12

// Input 2

10
7 9 3 2 9 1 6 4 10 8
10
1 5
2 6
3 7
3 9
3 10
4 5
4 7
4 10
5 7
7 9
26
*/