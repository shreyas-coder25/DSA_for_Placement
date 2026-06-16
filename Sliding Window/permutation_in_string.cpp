/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Constraints:
1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 > n2) {
            return false;
        } 
        vector<int> fr(26, 0);
        vector<int> wd(26, 0);
        for (int i=0; i<n1; i++) {
            fr[s1[i]-'a']++;
            wd[s2[i]-'a']++;
        }
        if (fr == wd) {
            return true;
        }
        for (int i=n1; i<n2; i++) {
            wd[s2[i]-'a']++; // 1
            wd[s2[i-n1]-'a']--; // 2
            if (wd == fr) {
                return true;
            }
        }
        return false;
    }
};

// IMportant Notes
// Time Complexity: O(n1+n2): Because we are traversing both strings once, where n1 is the length of s1 and n2 is the length of s2.
// Space Complexity: O(1)
// 1. Add the new character s2[i] to window.
// 2. Remove the old character that fell out of the window: s2[i - n1].

/* Let's say your window size is 3, and you are looking at the word "C-A-T".
When you slide the window one space to the right, you might now be looking at "A-T-S".

Notice what happened:

The "A" and the "T" stayed exactly where they were inside your window. You don't need to recount them!
- One old letter fell off the left side ("C").
- One new letter entered the right side ("S").

Instead of recounting the whole window from scratch, you take your existing fingerprint and simply make two tweaks:
> Subtract the frequency of the letter that just fell behind.
> Add the frequency of the new letter that just came into view.*/