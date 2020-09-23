#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
vector<bool> prime(200000001, true);
void get_seive(){
    
    prime[0] = false;
    prime[1] = false;

    for(int i = 4; i < 200000001; i += 2) prime[i] = false;

    for(int i = 3; i*i < 200000001; i += 2){
        if(prime[i]){
            for(int j = i*i; j < 200000001; j += i) prime[j] = false;
        }
    }
}

int main(){
    get_seive();
    vector<int> primes;
    for(int i = 1; i < 10000; i++){
        for(int j = 1; j < 100; j++){
            int inx = i*i + j*j*j*j;
            if( prime[inx] == true){
                primes.push_back(inx);
            }
        }
    }

    // for(int i = 1; i*i < 10000000; i++){
    //     for(int j = 1; j*j*j*j < 10000000; j++){
    //         if(prime[i*i + j*j*j*j] == true){
    //             primes.push_back(i*i + j*j*j*j);
    //         }
    //     }
    // }
    sort(primes.begin(), primes.end());
    unique(primes.begin(), primes.end());
    int t, n, size = primes.size();

    cin >> t;

    for(int tt = 0; tt < t; tt++){
        cin >> n;

        if(n == 1) cout << 0 << endl;
        else{
            int l = 0, h = size-1, mid = 0;
            while(l < h){
                mid = (l + h + 1)/2;
                if(primes[mid] > n) h = mid - 1;
                else l = mid;
            }
            cout << l + 1 << endl;
        }
    }
}

