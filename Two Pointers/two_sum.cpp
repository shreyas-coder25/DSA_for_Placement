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
        vector<pair<int, int>> p;
        for (int i=0; i<n; i++) {
            p.emplace_back(nums[i], i);
        }
        sort(p.begin(), p.end());
        int i=0, j=n-1;
        vector<int> ans;
        while (i < j) {
            int sum = p[i].first + p[j].first;
            if (sum == target) {
                ans.push_back(p[i].second);
                ans.push_back(p[j].second);
                break;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};

// Important Notes

// Time Complexity: O(n log n) due to sorting the array of pairs.
// Space Complexity: O(n) for storing the array of pairs and the answer vector.
// More optimized solution can be achieved using a hash map.