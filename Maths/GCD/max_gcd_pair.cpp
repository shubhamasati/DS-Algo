#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int n;

    cin >> t;
    for(int tt = 0; tt < t; tt++){
        cin >> n;
        for(int i = n; i > 1; i--){
            int half = (double)i/2;
            if(floor(half) == ceil(half)){
                 cout << (int)half << endl;
                 break;
            }
        }
    }
    return 0;
}