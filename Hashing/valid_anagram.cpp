/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
using all the original letters exactly once.

Constraints:
    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.
 
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        } 
        int n = s.length();
        int freq[26] = {0};
        for (int i=0; i<n; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for (int i=0; i<26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        } 
        return true;
    }
};

// Important Notes

/* Uses a frequency array to count the occurrences of each character in both strings. 
    Time complexity: O(n), Space complexity: O(1) (since the frequency array size is fixed at 26). 
    (more efficient than using a hash map, which would have O(n) space complexity) */
// Also solved using sorting