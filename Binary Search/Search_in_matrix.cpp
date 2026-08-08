/*
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int i=0, j=r-1;
        while (i <= j) {
            int k = i+ (j-i)/2;
            if (target>=matrix[k][0] && target<=matrix[k][c-1]) {
                int s=0, e=c-1;
                while (s <= e) {
                    int m = (s+e)/2;
                    if (matrix[k][m] == target) {
                        return true;
                    } else if (matrix[k][m] > target) {
                        e = m-1;
                    } else {
                        s = m+1;
                    }
                }
                return false;
            } else if (target > matrix[k][c-1]) {
                i = k+1;
            } else if (target < matrix[k][0]) {
                j = k-1;
            }
        }
        return false;
    }
};

// Important Notes
// Time Complexity: O(log(m*n)) = O(logm + logn) = O(logm) + O(logn)
// Space Complexity: O(1)
// Approach: Binary Search
// 1. First we will find the row in which the target can be present using binary search.
// 2. Then we will search for the target in that row using binary search.