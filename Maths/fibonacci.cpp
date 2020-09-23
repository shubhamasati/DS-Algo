#include <bits/stdc++.h>

using namespace std;

int f(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return f(n-2) + f(n-1);
}

int main(){

    int n;
    cin >> n;
    cout << f(n) << endl;
}
