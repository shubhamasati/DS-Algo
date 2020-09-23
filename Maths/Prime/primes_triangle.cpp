#include <bits/stdc++.h>
using namespace std;

vector<bool> is_prime(100000001, true);
map<int, pair<int, int>> cord;

void build_seive(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 4; i < 100000001; i += 2) is_prime[i] = false;
    for(int i = 3; i*i < 100000001; i += 2){
        if(is_prime[i]){
            for(int j = i*i; j < 100000001; j += i) is_prime[j] = false;
        }
    }
}

void build_cord(){
    int row = 2;
    int next = 3;
    int col = 1;
    cord.insert({2, {1, 1}});
    for(int i = 3; i < 100000001; i += 2){
        if(is_prime[i]){
            // if(i < 30) cout << i << endl;
            cord.insert({i, {row, col}});
            col++;
            if(col == next){
                col = 1;
                row++;
                next++;
            }
        }
    }


}


int main(){
    build_seive();
    build_cord();

    int t, n;
    cin >> t;

    for(int tt = 0; tt < t; tt++){
        cin >> n;
        if(!is_prime[n]) cout << -1 << endl;
        else cout << cord.at(n).first << " " << cord.at(n).second << endl;
    }
    
}