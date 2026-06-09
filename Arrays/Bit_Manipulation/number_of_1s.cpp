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

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Solution sol;
    cout << "Number of set bits: " << sol.hammingWeight(n) << endl;
    return 0;
}