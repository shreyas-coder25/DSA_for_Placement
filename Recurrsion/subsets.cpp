/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &arr, vector<int> &curr, int i) {
        if (i == arr.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(arr[i]);
        solve(ans, arr, curr, i+1); // Explore the subset including the current element
        curr.pop_back(); // Backtrack to explore the subset without the current element
        solve(ans, arr, curr, i+1); // Explore the subset excluding the current element
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, nums, curr, 0);
        return ans;
    }
};

// Important Notes 
// Time Complexity: O(2^n), for each element, we have two choices: either include it in the current subset or exclude it
// Space Complexity: O(n), The space is used for the recursion stack and the current subset being constructed.
// Logic:
// 1. The function `subsets` initializes the answer vector and a temporary vector to hold the current subset being constructed.
// 2. The recursive function `solve` is called with the initial index set to 0.
// 3. In the `solve` function, if i==size of array, it means we have considered all elements, and we add the current subset to the answer vector.
// 4. We then explore two possibilities for each element: including it in the current subset or excluding it, and recursively call `solve` for both cases.
// 5. The recursion continues until all subsets are generated, and the final answer is returned.