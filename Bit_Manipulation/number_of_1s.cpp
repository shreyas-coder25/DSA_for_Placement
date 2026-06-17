/*Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
Constraints:
1 <= n <= 231 - 1
Follow up: If this function is called many times, how would you optimize it?*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while (n > 0) {
            ans++;
            n = n & (n-1);
        }
        return ans;
    }
};

// Important points to note:
// Time complexity: O(k), where k is the number of set bits in n. In the worst case, k can be at most 31 (for a 32-bit integer).
// Space complexity: O(1). We use only a constant amount of extra space for the variable ans.
// Property of n & (n-1): This operation removes the lowest set bit from n. 
// Each time we perform this operation, we effectively count one set bit, which allows us to count all set bits in n efficiently.