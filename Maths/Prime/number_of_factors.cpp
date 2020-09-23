#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
void get_factors(ll n){
    int cnt = 0, ans = 1;
    ll num = n;
    bool first = true;
    for(ll i = 2; i*i <= num; i++){
        cnt = 0;
        while(n % i == 0){
            cnt++;
            n /= i;
        }
        if(cnt > 0){
            if(first){
                first = false;
                cout << num << " = " << i << "^" << cnt;
            } else cout << " * " << i << "^" << cnt ;
        }
        ans *= (cnt + 1);
    }
    cout << endl << "Total factors of the number are: "<< ans << endl;
}
int main(){

    long long n;
    cin >> n;

    get_factors(n);
    
}