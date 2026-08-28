/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example,
the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        int i=0, j=n-1;
        while (i < j) {
            int m = (i+j)/2;
            if (nums[m] > nums[j]) {
                i = m + 1; // The min is strictly to the right
            } else {
                j = m;     // The min is at m, or to the left
            }
    }
    // i and j converge exactly on the minimum element
    return nums[i];
    }
};

// Important Notes
// The algorithm uses a binary search approach to find the minimum element in a rotated sorted array.
// Methodology:
// 1. Initialize two pointers, i and j, to the start and end of the array respectively.
// 2. While i is less than j, calculate the middle index m.
// 3. Compare the middle element nums[m] with the last element nums[j]:
//    - If nums[m] is greater than nums[j], it means the minimum element is in the right half of the array, so we move the left pointer i to m + 1.
//    - Otherwise, the minimum element is in the left half of the array (including m), so we move the right pointer j to m.
// 4. When the loop ends, i and j will converge on the index of the minimum element, which is returned as nums[i].