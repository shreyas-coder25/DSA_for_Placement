/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int id) {
        if (id == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i=id; i<nums.size(); i++) {
            swap(nums[id], nums[i]); // Choose
            solve(nums, ans, id+1); // Explore
            swap(nums[id], nums[i]); // Backtrack
        }
        return;
    }
    vector<vector<int>> permutation(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, ans, 0);
        return ans;
    }
};

// Important Points:
// Time Complexity: O(n! * n) The n! comes from the number of permutations, additional n comes from copying the current permutation
// Space Complexity: O(n) for the recursion stack, and O(n) for storing the current permutation. Total = O(n) + O(n) = O(n)
// Method
// 1. We will use backtracking to generate all permutations of the given array.
// 2. Use a helper function solve() that takes the current index id and generates all permutations by swapping elements.
// 3. When we reach the end of the array (id == nums.size()), we add the current permutation to the answer vector.
// 4. We swap back the elements to backtrack and explore other permutations, from where we left off.
