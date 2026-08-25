/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, 
or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int t) {
        int s = 0;
        int e = nums.size()-1;
        while (s <= e) {
            int m = (s+e)/2;
            if (nums[m]==t) {
                return m;
            } else if (nums[m] >= nums[s]) { // when the left half is sorted
                if (t>=nums[s] && t<nums[m]) {
                    e = m-1;
                } else {
                    s = m+1;
                }
            } else {
                if (t>nums[m] && t<=nums[e]) { // when the right half is sorted
                    s = m+1;
                } else {
                    e = m-1;
                }
            }
        }
        return -1;
    }
};

// Important Notes
// Time Complexity: O(log n) 
// Space Complexity: O(1)
// Logic - 1. Check if the middle element is the target. If yes, return the index.
//         2. If the left half is sorted, check if the target lies in the left half. If yes, search in the left half, else search in the right half.
//        3. If the right half is sorted, check if the target lies in the right half. If yes, search in the right half, else search in the left half.