/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Constraints:
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i=0; i<n; i++) {
            int c = target-nums[i];
            if (m.find(c) != m.end()) {
                return {i, m[c]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};

// Important Notes

// Time Complexity: O(n) due to single pass through the array and O(1) average time for hash map operations.
// Space Complexity: O(n) for storing the hash map.