/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int s = 0;
        unordered_map<int, int> m;
        m[s]++;
        for (int j=0; j<n; j++) {
            s += nums[j]; // Calculates the prefix sum up to current element
            if (m.find(s-k) != m.end()) {
                ans += m[s-k]; // it was more than once up till now, so add the frequency
            }
            m[s]++; // add the current prefix sum in map
        }
        return ans;
    }
};

// Important Notes
// Time Complexity : O(n) We traverse the array once.
// Space Complexity: O(n)
// Method and logic
//     - initialize m[0] = 1; as starting sum of prefix = 0
//     - Find the prefix sum 
//     - Check if it was in the hash map
//     - if yes then add its count to ans