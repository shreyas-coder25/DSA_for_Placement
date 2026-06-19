/*You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. The large integer does 
not contain any leading 0's. Increment the large integer by one and return the resulting array of digits.

Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne_1(vector<int>& dig) {
        int n = dig.size();
        int c = 1;
        for (int i=n-1; i>=0; i--) {
            int sum = dig[i] + c;
            if (sum%10 != 0) {
                dig[i]++; c--;
                break;
            } else {
                dig[i] = 0;
                c = sum/10;
            }
        }
        if (c == 1) {
            dig.insert(dig.begin(), 1);
        }
        return dig;
    }
    vector<int> plusOne_2(vector<int>& dig) {
        int n = dig.size();
        for (int i=n-1; i>=0; i--) {
            if (dig[i] != 9) {
                dig[i]++;
                return dig;
            }
            dig[i] = 0;
        }
        dig[0] = 1;
        dig.push_back(0);

        return dig;
    }
};

// Important Notes

/* 1. Time Complexity = O(n), Space Complexity = O(1)
    Uses carry to prevent overflow at index when dig[i]=9.  
    insert function runs n times to shift all the indeices to right and put 1 at front. 
    This uses more time due to modulo and insert function.
*/

/* 2. Time Complexity = O(n), Space Complexity = O(1)
    Just checks if a digit is = 9 or not. And with clean code and less number of iterations, 
    it is more optimize than 1st approach.
*/