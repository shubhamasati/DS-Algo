#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> cost(N+1);
    cost[0] = 0;
    cost[1] = A[0];

    for(int i = 2; i < N+1; i++){
        cost[i] = 0;
        cost[i] = A[i-1] + min(cost[i-1], cost[i-2]);
    }
     cout << min(cost[N], cost[N-1]) << endl;

    return 0;
}