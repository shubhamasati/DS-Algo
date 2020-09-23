

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    
    for(int tt = 0; tt < t; tt++){
        cin >> n;
        vector<int> A(n);
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        int opn = 0;
        int m = ceil((double)n/2);
        int i = 0, j = n - 1;

        while( i < j){
            if(A[i] == A[j]){
                i++;
                j--;
            }else if(A[i] < A[j]){
                A[i+1] += A[i];
                i++;
                opn++;
            }else if(A[i] > A[j]){
                A[j-1] += A[j];
                j--;
                opn++;
            }
        }
        cout << opn << endl;
    }

}