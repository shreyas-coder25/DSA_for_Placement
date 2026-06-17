/* Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
ans[i] is the number of 1's in the binary representation of i.

Constraints:
0 <= n <= 105
 
Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). 
Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int setbits(int n) {
        int ans = 0;
        while (n > 0) {
            ans++;
            n = n & (n-1);
        }
        return ans;
    }
    vector<int> countBits(int n) {
        if (n == 0) {
            return {0};
        }
        vector<int> ans(n+1, 0);
        for (int i=1; i<=n; i++) {
            ans[i] = setbits(i);
        }
        return ans;
    }
};

// Important points to note:
// Time complexity: O(n * k), where k is the number of set bits in each number from 1 to n. In the worst case, k can be at most log(n) (for a number with all bits set).
// Space complexity: O(n). We use an array of size n+1 to store the number of set bits for each integer from 0 to n.
// It can be optimized further using dynamic programming or bit manipulation techniques to achieve O(n) time complexity.