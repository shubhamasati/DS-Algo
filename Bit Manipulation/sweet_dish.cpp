#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n){
    if(n == 2) return true;
    if(n < 2 || n % 2 == 0) return false;
    
    for(int i = 3; i < (int)sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int solve(vector<int> &A, int B, int C)
{
    
    int n = A.size();
    bool prime_arr[n];
    
    for(int i = 0; i < n; i++){
        if(is_prime(A[i])) prime_arr[i] = true;
        else prime_arr[i] = false;
    } 
    
    int cnt = 0;
    for(int i = 1; i < pow(2, n); i++){
        bool prime = false;
        int ingre = 0;
        for(int j = n-1; j > -1; j--){
            if( i >> j & 1 == 1){
                if(prime_arr[j]) prime = true;
                ingre += A[j];
            }
        }
        if( B <= ingre && ingre <= C && prime) cnt++;
    }
    return cnt;
}

int main(){

    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int B, C;
    cin >> B >> C;
    
    int ans = solve(A, B, C);
    cout << ans << endl;

}
/*
// Input

4
2 2 4 5
3 7

*/