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
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i=0; i<n; i++) {
            if (s[i] != t[i]) {
                return false;
            }
        } 
        return true;
    }
};

// Important Notes

/* Sorts both strings in alphabetical order and compares them. 
    Time complexity: O(n log n) due to sorting, 
    Space complexity: O(1) (ignoring the space used by sorting algorithms). 
    (less efficient than using a frequency array, which has O(n) time complexity) */