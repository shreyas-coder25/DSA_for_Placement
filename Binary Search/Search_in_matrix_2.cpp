/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Constraints:
m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r=0, c=n-1;
        while (r<m && c>=0) {
            if (matrix[r][c]==target) {
                return true;
            } else if (matrix[r][c]<target) {
                r++;
            } else {
                c--;
            }
        }
        return false;
    }
};

// Important Notes
// Time Complexity: O(m+n)
// Space Complexity: O(1)
// Approach: Binary Search
// 1. Start from the top right corner of the matrix.
// 2. If the target is equal to the current element, return true.
// 3. If the target is greater than the current element, move down to the next row.
// 4. If the target is less than the current element, move left to the previous column.

// Logic: The smallest element in the matrix is at the top left corner and the largest element is at the bottom right corner. 
// So, if the target is greater than the current element, we can eliminate the current row and move down to the next row. 
// If the target is less than the current element, we can eliminate the current column and move left to the previous column.