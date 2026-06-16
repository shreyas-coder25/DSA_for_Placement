/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 104*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        } 
        int b = prices[0], m = 0;
        for (int i=1; i<n; i++) {
            if (b < prices[i]) {
                m = max(m, prices[i]-b);
            } else {
                b = prices[i];
            }
        }
        return m;
    }
};

// Important Notes
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: We have to maximize the profit, means maximizing the difference between selling price and buying price. 
/*We can keep track of the minimum price seen so far and calculate the profit for each day by subtracting the minimum price from the current price. 
If the profit is greater than the maximum profit seen so far, we update the maximum profit. 
Else the current price is less than the minimum price, we update the minimum price. Finally, we return the maximum profit.*/