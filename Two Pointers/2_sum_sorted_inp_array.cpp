/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they 
add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] 
where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.
*/

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i=0, j=n-1;
        while (i < j) {
            long sum = numbers[i]+numbers[j];
            if (sum == target) {
                return {i+1, j+1};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};

// Notes:

// Time Complexity - O(N)
// Space Complexity - O(1)
