/*
    Problem Statement: Changu and Mangu are afraid of prime numbers, but they are not afraid of all
     prime numbers. They were afraid of only a special kind of prime numbers. They are afraid of the
     prime numbers (without the digit zero, they love all the primes which have digits 0 in them) that
     remain prime no matter how many of the leading digits are omitted. For example, they are afraid 
     of 4632647 because it doesn't have the digit 0 and each of its truncations (632647, 32647, 2647, 
     647, 47, and 7) are primes.
    You are given a simple task, given a number of N, find out the number of primes not greater that N, 
    that changu and mangu are afraid of.

    T ≤ 10^5
    1 ≤ N < 10^6

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> cnt(1000001, 0);
vector<bool> is_prime(1000001, true);
void build_seive(){
    
    is_prime[0] = false;
    is_prime[1] = false;

    for(int i = 4; i < 1000001; i += 2) is_prime[i] = false;

    for(int i = 3; i*i < 1000001; i += 2){
        if(is_prime[i]){
            for(int j = i*i; j < 1000001; j += i) is_prime[j] = false;
        }
    }
    // cout << "here" << endl;
}

bool is_afraidable(int n){
    int num = n;
    int digits = 0;
    while(num){
        if(num % 10 == 0) return false;
        num /= 10;
        digits++;
    }
    int mod = pow(10, digits-1);
    num = n;
    while(num > 0){
        num %= mod;
        mod /= 10;
        if(num != 0 && !is_prime[num]) return false;
    }
    return true;
}

void build_count(){
    for(int i = 2; i < 1000001; i++){
        cnt[i] = cnt[i-1];
        if(is_prime[i] && is_afraidable(i)) cnt[i] += 1;
    }
}

int main(){

    int t;
    cin >> t;
    build_seive();
    build_count();

    for(int tt = 0; tt < t; tt++){
        int n;
        cin >> n;
        cout << cnt[n] << endl;
    }
    

    return 0;
}