/*
    Problem statement: Say you have an array prices for which the ith element is the price of a given 
    stock on day i.Design an algorithm to find the maximum profit. You may complete as many transactions
    as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before 
you buy again).
*/


/*

    DP state: profit[i][0] = profit on ith day, with 0 stock in hand;
              profit[i][1] = profit on ith day, with 1 stock in hand;

    BaseCases: profit[0][0] = 0;
               profit[0][1] = -prices[0];


    recurrence relation: profit[i][0] = max(profit[i-1][0], profit[i-1][1] + prices[i]);
                         profit[i][1] = max(profit[i-1][1], profit[i-1][0] - prices[i]);
*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];

    // 2*N vector to store profit 
    vector<vector<int>> profit(n, vector<int>(2, 0));

    // BaseCase
    profit[0][0] = 0;
    profit[0][1] = -prices[0];

    for(int i = 1; i < n; i++){
        profit[i][0] = max(profit[i-1][0], profit[i-1][1] + prices[i]);
        profit[i][1] = max(profit[i-1][1], profit[i-1][0] - prices[i]);
    }
    cout << profit[n-1][0] << endl;

    return 0;
}
