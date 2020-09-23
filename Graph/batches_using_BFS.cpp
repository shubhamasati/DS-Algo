#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]){
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int M;
    cin >> M;
    vector<vector<int>> B(M, vector<int>(2, 0));
    for(int i = 0; i < M; i++){
        cin >> B[i][0] >> B[i][1];
    } 
    int D;
    cin >> D;

    vector<vector<int>> G(N);
    for(vector<int> a: B){
        G[a[0] - 1].push_back(a[1] - 1);
        G[a[1] - 1].push_back(a[0] - 1);
    }
    
    vector<bool> visited(N, false);
    queue<int> Q;
    
    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            
            Q.push(i);
            int strength = 0;
            
            while(!Q.empty())
            {
                int cur = Q.front();
                Q.pop();
                visited[cur] = true;
                strength += A[cur];
                
                for(auto n: G[cur])
                {
                   if(!visited[n]) Q.push(n);
                }    
            }
            
            if(strength >= D)
            {
                ans++;
            } 
        }
    }
    cout << ans << endl;
    return 0;
}