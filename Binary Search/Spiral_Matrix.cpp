/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sr=0, er=m-1, sc=0, ec=n-1;
        vector<int> nums;
        while (sr<=er && sc<=ec) {
            for (int i=sc; i<=ec; i++) { // Top
                nums.push_back(matrix[sr][i]);
            }
            for (int j=sr+1; j<=er; j++) { // Right 
                nums.push_back(matrix[j][ec]);
            }
            for (int i=ec-1; i>=sc; i--) { // Bottom
                if (sr==er) break;
                nums.push_back(matrix[er][i]);
            }
            for (int j=er-1; j>=sr+1; j--) { // Left
                if (sc==ec) break;
                nums.push_back(matrix[j][sc]);
            }
            sr++; er--;
            sc++; ec--;
        }
        return nums;
    }
};

// Important Notes
// Time Complexity: O(m*n)
// Space Complexity: O(1) (not counting the output array)
// Approach: Spiral Order Traversal
// 1. We will maintain four pointers: sr (start row), er (end row), sc (start column), ec (end column).
// 2. We will traverse the matrix in a spiral order by moving right, down, left, and up, while updating the pointers accordingly until we have traversed all elements of the matrix.
// 3. We will return the result in a vector.

