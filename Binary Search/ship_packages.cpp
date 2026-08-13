/*
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Constraints:

1 <= days <= weights.length <= 5 * 104
1 <= weights[i] <= 500
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvalid(vector<int> &arr, int n, int d, int mid) {
        int day = 1;
        int w = 0;
        for (int i=0; i<n; i++) {
            if (w+arr[i] <= mid) {
                w+=arr[i];
            } else {
                day++;
                w = arr[i];
            }
        }
        return day<=d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int i=0, j=0;
        for (int &w: weights) {
            i = max(i,w);
            j += w;
        }
        int ans = 0;
        while (i <= j) {
            int m = i+(j-i)/2;
            if (isvalid(weights, n, days, m)) {
                ans = m;
                j = m-1;
            } else {
                i = m+1;
            }
        }
        return ans;
    }
};

// IMportant Notes
// Time Complexity: O(nlog(sum of weights - max weight))
// Space Complexity: O(1)
// Similar to The Painter's Partition Problem, Book Allocation Problem, Agressive Cow Problem
// Approach: Binary Search on Answer
// 1. Find the maximum weight and sum of weights in the array. This will be the range for binary search.
// 2. Use binary search to find the minimum weight capacity of the ship that can ship all packages within the given days.
// 3. For each mid value, check if it is valid by simulating the shipping process and counting the number of days required. 
// If it is valid, update the answer and search for a smaller capacity. If it is not valid, search for a larger capacity.
// 4. Validity check: Iterate through the weights and keep adding them to the current weight until it exceeds the mid value. 
//  When it exceeds, increment the day count and reset the current weight to the current package weight. 
//  If the day count exceeds the given days, return false. Otherwise, return true.