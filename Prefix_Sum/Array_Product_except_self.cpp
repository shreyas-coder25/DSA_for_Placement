/*Given an integer array nums, return an array answer such that answer[i] 
is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Constraints:
    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 
Follow up: Can you solve the problem in O(1) extra space complexity? 
(The output array does not count as extra space for space complexity analysis.)*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int i=0, j=n-1;
        int p=1, s=1;
        while (i < n && j >= 0) {
            ans[i] *= p;
            ans[j] *= s;
            p *= nums[i];
            s *= nums[j];
            i++; j--;
        }
        return ans;
    }
};

// Important points

// Time complexity: O(n) as we traverse the array once.
// Space complexity: O(1) as we are using the output array to store the results and not using any extra space.
// To modify the input array, we can store product of all elements in a variable and then divide it by each element to get the result. 
// However, this approach is not allowed as we cannot use division operation in this question.