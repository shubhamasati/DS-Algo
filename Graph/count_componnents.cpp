#include<iostream>
#include<queue>

using namespace std;
int main(){

	int n;

	cin >> n;
    
    vector<int> G[n+1];

    int u, v;

	while(cin >> u >> v){
		G[u].push_back(v);
		G[v].push_back(u);
	}

	cout << G;

	return 0;
}

/*

7
1 2
2 3
3 1
4 5
6 7

*/