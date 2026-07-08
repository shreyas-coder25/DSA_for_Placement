/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.*/

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent_1(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        for (int i: nums) {
            f[i]++;
        }
        vector<pair<int, int>> freq;
        for (auto &i: f) {
            freq.emplace_back(i.first, i.second);
        }
        sort(freq.begin(), freq.end(), [](const pair<int, int> &a, const pair<int, int> &b){return a.second > b.second;});

        vector<int> ans;

        for (auto i: freq) {
            if (ans.size() == k) {
                break;
            }
            ans.push_back(i.first);
        }
        return ans;
    }
    vector<int> topKFrequent_2(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> f;
        for (int i: nums) {
            f[i]++;
        }
        vector<vector<int>> bucket(n+1);
        for (auto &i: f) {
            bucket[i.second].push_back(i.first);
        }
        vector<int> ans;
        for (int i=n; i>0 && ans.size()<k; i--) {
            auto &vec = bucket[i];
            for (int i: vec) {
                ans.push_back(i);
                if (ans.size() == k) {
                    break;
                } 
            }
        }
        return ans;
    }
};

// Important Notes

// 1. 
// The first solution uses sorting which has a time complexity of O(n log n).
// Space complexity is O(n) due to the unordered_map and vector used to store frequencies.
// Stepwise method - 
// 1) Count the frequency of each element using an unordered_map. 
// 2) Store the elements and their frequencies in a vector of pairs. 
// 3) Sort the vector based on frequencies in descending order. 
// 4) Extract the top k elements from the sorted vector and return them as the result.

// 2.
// The second solution uses bucket sort which has a time complexity of O(n).
// Space complexity is O(n) due to the unordered_map and vector used to store frequencies and buckets.
// Method -
// 1) Count the frequency of each element using an unordered_map.
// 2) Create a vector of vectors (buckets) where the index i is the frequency vector consisting of elements with that frequency.
// 3) Iterate through the buckets in reverse order (from highest frequency to lowest) and collect elements until we have k elements.