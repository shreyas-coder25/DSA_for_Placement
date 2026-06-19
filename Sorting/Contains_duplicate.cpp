/*Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.

Constraints:
> 1 <= nums.length <= 105
> -109 <= nums[i] <= 109*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) { // Using sorting
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-1; i++) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};

/* Notes */

/* containsDuplicate: Uses sorting to check for duplicates. 
Time complexity: O(n log n), Space complexity: O(1).
(still uses less runtime and memory due to less CPU overhead) */

