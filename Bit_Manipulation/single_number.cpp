/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Constraints:
1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 ) {
            return nums[0];
        } 
        int ans = 0; 
        for (int i=0; i<n; i++) {
            ans ^= nums[i];
        }
        return ans;
    } 
};

// Important points to note:
// Time complexity: O(n). We iterate through the array once.
// Space complexity: O(1). We use only a constant amount of extra space for the variable ans.
// XOR Property: for any integer x, x ^ x = 0 and x ^ 0 = x. 
// This means that pairs of identical numbers will cancel each other out, leaving only the unique number as the result.