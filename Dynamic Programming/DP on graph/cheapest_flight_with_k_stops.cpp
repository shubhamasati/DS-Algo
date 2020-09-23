#include <bits/stdc++.h>
using namespace std;

struct node{
    int airport;
    int k_left;
    int cost;
};

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> G(n, vector<pair<int, int>>());
    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    } 

    vector<int> cost_to_node(n, INT32_MAX);
    int src, dest, k;
    cin >> src >> dest >> k;
    
    queue<node> Q;
    Q.push({src, k, 0});
    
    int min_cost = INT32_MAX;
    while(!Q.empty()){
        node p = Q.front();
        Q.pop();
        int cur_airport = p.airport;
        int k_left = p.k_left;
        int cost = p.cost;

        if(cur_airport == dest) min_cost = min(min_cost, cost);

        if(k_left >= 0){
            for(auto n: G[cur_airport]){
                // cout << cur_airport << " " << n.first << " " << cost + n.second << endl;
                if(cost_to_node[n.first] > cost + n.second){
                    Q.push({n.first, k_left - 1, cost + n.second});
                    cost_to_node[n.first] = cost + n.second;
                }
            }
        }
    }
    std::cout << min_cost << endl;
    return 0;
}

