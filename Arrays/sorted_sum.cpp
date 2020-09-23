#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> A, int start, int mid, int end){
    
}
void merge_sort(vector<int> A, int start, int end){

    if(start < end){
        int mid = start + (end - start) >> 1;
        merge_sort(A, start, mid-1);
        merge_sort(A, mid, end);
        merge(A, start, mid, end);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    merge_sort(A, 0, n-1);
    return 0;
}