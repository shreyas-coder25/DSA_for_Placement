/*Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.

Constraints:
> 1 <= nums.length <= 105
> -109 <= nums[i] <= 109*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) { // Using hash set
        int n = nums.size();
        unordered_set<int> s; 
        for (int i: nums) {
            if (!s.insert(i).second) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }
    Solution sol;
    if (sol.containsDuplicate(nums)) {
        cout << "The array contains duplicates." << endl;
    } else {
        cout << "The array does not contain duplicates." << endl;
    }
    return 0;
}

// Important Notes

/* Uses a hash set to check for duplicates. Time complexity: O(n), Space complexity: O(n). 
    (uses more memory and more runtime too, because of the additional data structure and CPU overhead) */