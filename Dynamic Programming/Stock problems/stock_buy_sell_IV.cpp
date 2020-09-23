/*
    Problem Statement: Say you have an array for which the i-th element is the price of a given stock 
    on day i. Design an algorithm to find the maximum profit. You may complete at most k transactions.

    Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock 
    before you buy again).
*/

/*
    Goal: Maximize profit on the last day by performing at most K transactions;

    DP state: profit[i][j] = profit on ith day by performing at most j transactions;

    Base Case:
        if k = 0 that  means we can not perform any transaction then the row with j = 0 will be 0;
        if we have only one price available then we can not complete the transaction then column with 
        i = 0 will be 0;
    
    Recurrence Relation: profit[i][j] = max(profit[i-1][j], profit[m-1][j-1] + price[i] - price[m])
        Where m is 0 to i -1;

*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];

    int k;
    cin >> k;
    // Stock buy sell with any number of transaction(Stock buy sell II)
    if(k >= n/2){
        int profit = 0;
        for(int i = 0; i < n-1; i++){
            if(prices[i] < prices[i+1]) profit += prices[i+1] - prices[i];
        }
        cout << profit << endl;
        return 0;
    }
    
    // Stock buy sell with k transactions(stock buy sell III)
    vector<vector<int>> profit(n + 1, vector<int>(k+1 , 0));
    for(int j = 1; j < k + 1; j++){
        int max_diff = -prices[0];
        for(int i = 2; i < n + 1; i++){
            profit[i][j] = max(profit[i-1][j], prices[i-1] + max_diff);
            max_diff = max(max_diff, profit[i][j-1] - prices[i-1]);
        }
    }
    cout << profit[n][k] << endl;

    return 0;
}
