/*
`   Problem statement: Say you have an array for which the ith element is the price of a given stock 
on day i. If you were only permitted to complete at most one transaction (i.e., buy one and sell one 
share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.
*/

/*
    Goal: to maximize the profit at the last day.

    Condition(requirment): we can not sell the stock before buying.

    DP state: profit[i] --> profit gained on day i;
    
    BaseCases: profit[1] = 0;

    Recurrence Relation: profit[i] = price[i] - min(price[0: i- 1]);
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];

    // we need some precomputation here 
    // We will calculate the minimum price till index i.
    vector<int> min_price(n);
    min_price[0] = prices[0];

    for(int i = 1; i < n; i++) min_price[i] = min(min_price[i-1], prices[i]);

    // initially we have 0 profit.
    int profit = 0;
    for(int i = 0; i < n; i++) profit = max(profit, prices[i] - min_price[i]);

    cout << profit << endl;
}