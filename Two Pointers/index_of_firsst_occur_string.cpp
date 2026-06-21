/*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.

Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr_1(string hs, string ndl) {
        int n = hs.length();
        int m = ndl.length();
        if (n < m) {
            return -1;
        }
        for (int i=0; i<n-m+1; i++) {
            int j = 0;
            while (j<m && hs[i+j]==ndl[j]) {
                j++;
            }
            if (j == m) {
                return i;
            } 
        }
        return -1;
    }
};

// Important Points

// 1. Brute Force Approach: 
// Time Complexity: O(n*m) where n is the length of haystack and m is the length of needle.
// Space Complexity: O(1) as we are not using any extra space.

// 2. Two Pointers Approach: KMP Algorithm