/*Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.

Constraints:
n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
 
Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        nums.resize(n+1);
        int ans = 0;
        for (int i=0; i<=n; i++) {
            if (nums[i] != i) {
                ans = i;
                return i;
            } 
        }
        return ans;
    }
};

// Using Cycle sort:



// Important Points:
// Time Complexity: O(n log n) due to sorting the array.
// Space Complexity: O(1) if we ignore the space used by the sorting algorithm, otherwise O(n) due to resizing the array.
// Note: The above solution does not meet the O(n) runtime complexity requirement due to the sorting step.
// Three most optimimal solutions to this problem are:
// 1. Using the formula for the sum of the first n natural numbers: sum = n*(n+1)/2, and then subtracting the sum of the elements in the array from this total.
// 2. Using the XOR operation: XOR all the numbers from 0 to n and XOR all the numbers in the array. The result will be the missing number.
// 3. Cyclic Sort: Place each number in its correct index and then find the missing number by checking which index does not have the correct number.
