/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Constraints:
    1 <= s.length <= 2 * 105
    s consists only of printable ASCII characters.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s) {
        int n = s.length();
        int i=0, j=n-1;
        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
            } else if (!isalnum(s[j])) {
                j--;
            } else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                i++; j--;
            }
        }
        return true;
    } 
};

// Important points
// Time complexity: O(n) as we traverse the string once.
// Space complexity: O(1) as we are using constant space to store the pointers and not using any extra space.
// We can also use a stack/deque to store the characters and then compare it with the original string, but that would require O(n) space complexity.
// 