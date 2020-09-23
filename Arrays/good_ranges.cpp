#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    
    cout << *s.end() << " " << *s.begin() << " " << s.count(2) << endl;
    return 0;
}