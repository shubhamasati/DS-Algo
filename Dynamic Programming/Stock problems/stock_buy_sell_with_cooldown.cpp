/*
    Problem Statement: Say you have an array for which the ith element is the price of a given stock on
    day i. Design an algorithm to find the maximum profit. You may complete as many transactions as you
    like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
      1. You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
      2. After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
*/

/*

    Goal: Maximize the profit on last day with 0 stock in hand;

    conditions: We can not buy stock just after selling the stock;
                we dont have restriction on selling the stock;

    DP state: profit[i][0] = profit on ith day, with 0 stock in hand;
              profit[i][1] = profit on ith day, with 1 stock in hand;

    Base Cases: 
              profit[0][0] = 0;
              profit[0][1] = -prices[0];

              profit[1][0] = max(profit[0][0], profit[0][1] + prices[1]);
              profit[1][1] = max(profit[0][1], -prices[1]);
    
    recurrence relation:
              profit[i][0] = max(profit[i-1][0], profit[i-1][1] + prices[i]);
              profit[i][1] = max(profit[i-1][1], profit[i-2][0] - prices[i]);

*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n ;
    cin >> n;

    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];

    vector<vector<int>> profit(n, vector<int>(2, 0));

    // Base Cases
    profit[0][0] = 0;
    profit[0][1] = -prices[0];

    profit[1][0] = max(profit[0][0], profit[0][1] + prices[1]);
    profit[1][1] = max(profit[0][1], -prices[1]);
    
    for(int i = 2; i < n; i++){
        profit[i][0] = max(profit[i-1][0], profit[i-1][1] + prices[i]);
        profit[i][1] = max(profit[i-1][1], profit[i-2][0] - prices[i]);
    }
    cout << profit[n-1][0] << endl;

    return 0;
}
