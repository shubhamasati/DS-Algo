#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(){
    int A;
    cin  >> A;
    
    int N;
    cin >> N;
    vector<int> B(N);
    vector<int> C(N);

    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    
    vector<int> indegree(A, 0);
    vector<vector<int>> G(A);
    
    for(int i = 0; i < N; i++){
        G[C[i]-1].push_back(B[i]-1);
        indegree[B[i]-1]++;
    }

    queue<int> Q;
    int course_completed = 0;
    vector<bool> visited(A, false);

    for(int i =0; i < A; i++){
        if(indegree[i] == 0){
            // visited[i] = true;
            Q.push(i);
        }
    }

    while(!Q.empty()){
        int cur = Q.front();
        visited[cur] = true;
        course_completed++;
        Q.pop();
        for(auto n: G[cur]){
            indegree[n]--;
            if(indegree[n] == 0){
                Q.push(n);
            }
        }
    }

    if(course_completed == A) cout << '1' << endl;
    else cout << '0' << endl;

    return 0;
}

/*
3
2
1 2
2 3

*/