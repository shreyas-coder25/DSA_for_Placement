/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum_1(vector<int>& nums) { // Brute Force Approach
        int n = nums.size();        
        vector<vector<int>> ans;
        set<vector<int>> s; // to store such data, custom hash is to be written in unordered set.
        // to make simple use set instead
        
        for (int i=0; i<n; i++) {
            int a = nums[i];
            for (int j=i+1; j<n; j++) {
                int b = nums[j];
                for (int k=j+1; k<n; k++) {
                    int c = nums[k];
                    if (a+b+c == 0) {
                        vector<int> temp = {a, b, c};
                        sort(temp.begin(), temp.end());
                        if (!s.count(temp)) {
                            ans.push_back(temp);
                            s.insert(temp);
                        }
                    }
                }
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum_2(vector<int>& nums) { // Hashing Approach
        int n = nums.size();        
        vector<vector<int>> ans;
        set<vector<int>> s2; 
        for (int i=0; i<n; i++) {
            int a = nums[i];
            set<int> s1;
            for (int j=i+1; j<n; j++) {
                int c = -a-nums[j];
                if (s1.count(c)) {
                    vector<int>temp = {a, nums[j], c};
                    sort(temp.begin(), temp.end());
                    if (!s2.count(temp)) {
                        ans.push_back(temp);
                        s2.insert(temp);
                    }
                }
                s1.insert(nums[j]);
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) { // Two Pointers Approach
        int n = nums.size();  
        sort(nums.begin(), nums.end());      
        vector<vector<int>> ans;
        for (int i=0; i<n-2; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue; // skip duplicates
            int j=i+1, k=n-1;
            while (j < k) { // two pointers to find the other two numbers
                int s = nums[i]+nums[j]+nums[k];
                if (s == 0) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while (nums[j]==nums[j-1] && j<k) j++; // skip duplicates, so the triplet is unique
                } else if (s < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};

// Important Notes
// 1. Brute Force Approach
// Time Complexity: O(n^3*log(temp)) where n is the size of the input array. We are using three nested loops to find all triplets.
// Space Complexity: O(n) where n is the size of the input array. We are using a set to store unique triplets.
// 2. Hashing Approach
// Time Complexity: O(n^2*log(temp)) where n is the size of the input array. We are using two nested loops to find all triplets.
// Space Complexity: O(n) where n is the size of the input array. 
// We are using a set to store unique triplets and another set to store the elements we have seen so far.
// 3. Two Pointers Approach
// Time Complexity: O(n^2 + nlog(n)) where n is the size of the input array. We are using two nested loops to find all triplets.
// Space Complexity: O(1) where n is the size of the input array. We are not using any extra space to store unique triplets.