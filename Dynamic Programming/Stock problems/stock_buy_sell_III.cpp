/*
    Problem statement: Say you have an array for which the ith element is the price of a given stock on 
                       day i. Design an algorithm to find the maximum profit. You may complete at most 
    two transactions.
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before 
you buy again).

*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    
    // We should have at least two days to make a profit
    // 1 day for buying and 1 day for selling
    if(n < 2){
        cout << 0 << endl;
        return 0;
    }

    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];

    vector<int> min_price(n);
    vector<int> max_price(n);

    min_price[0] = prices[0];
    max_price[n-1] = prices[n-1];

    for(int i =0; i < n; i++){
        if(i > 0) {
            min_price[i] = min(min_price[i - 1], prices[i]);
            max_price[n - 1 - i] = max(max_price[n - i], prices[n - 1 - i]);
        }
    }

    vector<int> profit_for_one(n);
    profit_for_one[0] = 0;
    
    int profit = 0;
    for(int i = 1; i < n; i++){
        profit_for_one[i] = max(profit_for_one[i-1], prices[i] - min_price[i]);
        profit = max(profit, profit_for_one[i-1] + max(0, max_price[i] - prices[i]));
    }
    profit_for_one[n-1] = max(0, prices[n-1] - min_price[n-1]);
    cout << max(profit, profit_for_one[n-1]) << endl;

    return 0;
}
