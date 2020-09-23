/*
    SPOJ problem 
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

# define N 100000001

vector<int> get_sieve(){
	int sqrt_num = (int)sqrt(N);
	
	vector<bool> is_prime(N, true);
	vector<int> primes;
	is_prime[0] = false;
	is_prime[1] = false;
	
	for(int i = 2; i < N; i += 2) is_prime[i] = false;
	primes.push_back(2);
	for(int i = 3; i < sqrt_num + 1; i++){
		if(is_prime[i]){
            primes.push_back(i);
			for(int j = i*i; j < N; j += i) is_prime[j] = false;
		}
	}
    int i = sqrt_num % 2 == 0? sqrt_num + 1: sqrt_num + 2;
    // cout << i << endl;
    for(int j = i; j < N; j += 2){
        if(is_prime[j]) primes.push_back(j);
    }
        
	return primes;
}
int main() {
	vector<int> primes = get_sieve();
	// vector<int> primes;
	// for(int i = 2; i < N; i) if(sieve[i]) primes.push_back(i);
	
    for(int i = 0; i < primes.size(); i += 100){
        // if(primes[i] == 0) break;
        cout << primes[i] << endl; 
    } 
	return 0; 
}