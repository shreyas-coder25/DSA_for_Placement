/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int b=0; b<9; b++) {
            unordered_set<char> s;
            int r = b/3*3;
            int c = b%3*3;
            for (int i=0; i<3; i++) {
                for (int j=0; j<3; j++) {
                    char ch = board[r+i][c+j];
                    if (ch == '.') continue;
                    if (s.count(ch)) return false;
                    s.insert(ch);
                }
            }
        }
        for (int i=0; i<9; i++) {
            unordered_set<char> s;
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue; 
                if (s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }
        for (int i=0; i<9; i++) {
            unordered_set<char> s;
            for (int j=0; j<9; j++) {
                if (board[j][i] == '.') continue; 
                if (s.count(board[j][i])) return false;
                s.insert(board[j][i]);
            }
        }
        return true;
    }
};

// Notes
// 1. The solution uses three separate loops to check the validity of the Sudoku board:
//    - The first loop checks each of the nine 3x3 sub-boxes for duplicates.
//    - The second loop checks each row for duplicates. 
//   - The third loop checks each column for duplicates.
// 2. The use of unordered_set allows for O(1) average time complexity for insertions and lookups, making the solution efficient.