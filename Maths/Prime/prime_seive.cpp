#include <bits/stdc++.h>
using namespace std;

void build_seive(int n){

    vector<int> prime(n+1, 1);

    prime[0] = 0;
    prime[1] = 0;

    for(int i = 4; i < n+1; i += 2) prime[i] = 0;

    for(int i = 3; i * i <= n+1; i += 2){
        if(prime[i] == 1){
            for(int j = 2*i; j < n+1; j += i) prime[j] = 0;
        }
    }

    for(int i = 2; i < n+1; i++){
        if(prime[i] == 1) cout << i << endl;
    }

}


int main(){

    int n;
    cin >> n;
    build_seive(n);
}