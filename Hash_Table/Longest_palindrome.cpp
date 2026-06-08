/* Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Constraints:
> 1 <= s.length <= 2000
> s consists of lowercase and/or uppercase English letters only.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char c: s) {
            m[c]++;
        }
        int ans = 0, o = 0;
        for (auto i: m) {
            ans += i.second - (i.second%2);
            if (i.second % 2 != 0) {
                o++;
            }
        }
        if (o > 0) {
            return ans+1;
        }
        return ans;
    }
};

int main() {
    string s;
    cout << "Enter a string";
    cin >> s;
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}