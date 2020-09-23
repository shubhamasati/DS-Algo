#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

bool check_bipartite(vector<int> G[], int N){
    
    cout << "here we reached";
    set<int> color[2];
    bool visited[N];

    queue<int> q;
    
    for(int i = 0; i < N; ++i) visited[i] = false;

    for(int i = 0; i < N; ++i){
    	
    	if(!visited[i]){
    		q.push(i);

	    	while( q.size() > 0){
	    		int cur_node = q.front();
	    		q.pop();

	    		int cur_color = color[0].find(cur_node) != color[0].end() ? 0: 1;

	    		for(int n: G[cur_node]){
	    			if(!visited[n]){
	    				q.push(n);
	    				if(color[cur_color].find(n) != color[cur_color].end()) return false;
	    				if(color[1 - cur_color].find(n) != color[1 - cur_color].end()) color[1 - cur_color].insert(n);
	    			}
	    		}
	    	}
	    }

    }

 	return true;
}


int main(int argc, char const *argv[])
{
/*
	//Input - 1
	2
	0 1

*/
	int N, E;
	cin >> N >> E;

	vector<int> G[N];

	int u, v;
	for(int i = 0; i < E; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);

		// cout << u     << "   " << v << endl;
	}
	cout << check_bipartite(G, N);
	return 0;
}

/*
3 3
0 1
0 2
1 2

*/
