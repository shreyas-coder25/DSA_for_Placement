/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    void solve(vector<int> &arr, vector<int> &curr, vector<vector<int>> &ans, int i) {
        if (i == arr.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(arr[i]);
        solve(arr, curr, ans, i+1);
        curr.pop_back();
        int id = i+1;
        while (id<arr.size() && arr[id]==arr[id-1]) {
            id++;
        }
        solve(arr, curr, ans, id);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, curr, ans, 0);
        return ans;
    }
};

// Important Notes 
// Time: O(n × 2ⁿ) because we generate all subsets and copying each subset takes O(n)
// Space: O(n) due to recursion stack and current subset.
// Method: Similar to the subsets question. just introduced the while loop to skip the duplicate elements
// the subsets are repeated when the element excluded is included once again, so it is necessary to skip its duplicate in array. 
// we used new variable id instead of i, because-
// It keeps i unchanged, representing the index of the current element.
// The code is easier to understand.
// It avoids bugs when you later add logic that still needs the original value of i.