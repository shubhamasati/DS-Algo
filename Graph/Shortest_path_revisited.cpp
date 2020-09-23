#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int city = 0;
    int cost = 0;
    int passes_left = 0;
};

class CompareDis{
    public:
        bool operator() (const pair<int, int>& n1, const pair<int, int>& n2){
            return n1.second > n2.second;
        }
};

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> G(n+1, vector<pair<int, int>>());
    
    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<vector<bool>> visited(n+1, vector<bool>(k+1, false));
    // priority_queue<Node,  vector<Node>, CompareDis> Q;
    queue<pair<int , pair<int, int>>> Q;
    vector<int> cost_to_city(n+1, INT32_MAX);

    Q.push({1, 0});

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();
        int cur_city = cur.first;
        int cost = cur.second;

        cost_to_city[cur_city] = min(cost_to_city[cur_city], cost);
        cout << cur_city << " " <<cost << endl;
        Q.pop();

        for(auto nxt: G[cur_city]){
            //cout << cur_city << " " << nxt.first << " " << passes_left << " " << cost << endl; 
            if(!visited[cur_city][nxt.first]){
                // cout << cur_city << " " << nxt.first << " " << passes_left << " " << cost << endl;
                Q.push({nxt.first, cost + nxt.second, passes_left});
                if(passes_left > 0){
                    Q.push({nxt.first, cost, passes_left-1});
                }
               
                visited[cur_city][nxt.first] = true;
            }    
        }
    }
    
    for(auto x: cost_to_city) cout << x << " ";
    
}

/*
4 5 1
1 2
2 3
1 4
3 4
2 4

*/