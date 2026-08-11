/* 
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate_1(vector<int>& nums) { // Hashing approach
        int n = nums.size();
        unordered_set<int> s;
        for (int &i: nums) {
            if (s.count(i)) return i;
            s.insert(i);
        }
        return -1;
    }
    int findDuplicate(vector<int>& nums) { // Fast and slow pointer approach
        int n = nums.size();
        int s=nums[0], f=nums[0];
        do {
            s = nums[s]; //+1
            f = nums[nums[f]]; //+2
        } while (s != f);

        s = nums[0];
        while (s != f) {
            s = nums[s]; 
            f = nums[f];
        }
        return s;
    }
};

// Important Notes

// 1. The first approach uses hashing to find the duplicate number, which requires O(n) extra space.
// Time complexity: O(n), Space complexity: O(n)

// 2. The second approach uses the Floyd's Cycle Detection algorithm (also known as the Tortoise and Hare algorithm) 
// Time complexity: O(n), Space complexity: O(1)
// Method: Assume the array as a linked list where each index points to the value at that index. 
// Since there is a duplicate, there will be a cycle in this linked list. 
// The fast and slow pointer technique is used to detect the cycle and find the entry point of the cycle, 
// which corresponds to the duplicate number in the array.