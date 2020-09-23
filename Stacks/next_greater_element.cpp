#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    stack<int> s1;
    stack<int> s2;

    vector<int> greater(n);
    vector<int> smaller(n);
    s1.push(0);
    s2.push(0);

    for(int i = 1; i < n; i++){
        //  checking for next greater element
        while(!s1.empty() && arr[s1.top()] < arr[i]){
            greater[s1.top()] = i;
            s1.pop();
        }
        s1.push(i);

        // checking for next smaller element
        while(!s2.empty() && arr[s2.top()] > arr[i]){
            smaller[s2.top()] = i;
            s2.pop();
        }
        s2.push(i);
    }

    while(!s1.empty()){
        greater[s1.top()] = -1;
        s1.pop();
    }

    while(!s2.empty()){
        smaller[s2.top()] = -1;
        s2.pop();
    }

    for(int i = 0; i < n; i++){
        if(smaller[i] == -1) cout << -1 << endl;
        else cout << arr[greater[smaller[i]]] << endl;
    }

    return 0;
}