/*
    Problem Statement: A cube free number is a number who’s none of the divisor is a cube number 
    (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers 
    are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 
    8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers 
    is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say 
    if its a cube free number and if yes then tell its position among cube free numbers.

Input:  First line of the test case will be the number of test case T (1 <= T <= 100000) . Then T lines
follows. On each line you will find a integer number n (1 <= n <= 1000000).

Output:  Output
For each input line, print a line containing “Case I: ”, where I is the test case number. Then if it is 
not a cube free number then print “Not Cube Free”. Otherwise print its position among the cube free numbers.

*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> is_cube_free(10e6 + 1, true);
vector<int> cube_free(10e6 + 1, -1);

void build_cube_free(){

    for(int i = 2; i < 101; i++){
        int inc = i*i*i;
        if(is_cube_free[inc]){
            for(int j = inc; j < 10e6 +1; j += inc){
                is_cube_free[j] = false;
            }
        }
    }

    int index = 1;
    for(int i = 1; i < 10e6 +1; i++){
        if(is_cube_free[i]){
            cube_free[i] = index;
            index++;
        }
    }
}


int main(){

    int t;
    cin >> t;

    build_cube_free();
    int n;
    for(int ii = 0; ii < t; ii++){
        cin >> n;
        if(cube_free[n] != -1) cout << "Case " << ii + 1 << ": " <<  cube_free[n] << endl;
        else cout << "Case " << ii + 1 << ": " << "Not Cube Free" << endl;
    }
}