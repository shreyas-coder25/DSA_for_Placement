/*
Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            for (int j=i+1; j<n-2; j++) { 
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                int l=j+1, r=n-1;
                while (l < r) { 
                    long long s = (long long)nums[i]+nums[j]+nums[l]+nums[r];
                    if (s == target) {
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while (l<r && nums[l]==nums[l-1]) l++; 
                    } else if (s < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
