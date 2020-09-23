#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

// calculate the seive of size N
vector<bool> get_seive(int N){
    vector<bool> seive(N+1, true);

    int sqrtN = (int)sqrt(N);

    seive[1] = false;
    seive[2] = true;
    for(int i = 4; i < N+1; i += 2) seive[i] = false;

    for(int i = 3; i < sqrtN; i += 2){
        if(seive[i]){
            for(int j = i*i; j < N+1; j += i) seive[j] = false;
        }
    }
    return seive;
}


int main(){

    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<bool> seive = get_seive(*max_element(A.begin(), A.end()));
    
    int count = 0;
    for(auto i: A) if(seive[i]) count++;
    
    long long ans = pow(2, count);

    cout << (ans - 1) % 1000000007;

    return 0;
}