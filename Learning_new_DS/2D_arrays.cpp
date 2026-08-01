#include <bits/stdc++.h>
using namespace std;

int maxcol(int arr[][3], int r, int c) {
    int m = INT_MIN;
    for (int i=0; i<c; i++) {
        int sum = 0;
        for (int j=0; j<r; j++) {
            sum += arr[j][i];
        }
        m = max(m, sum);
    }
    return m;
} 

int sum_diag(int arr[][3], int r, int c) {
    if (r != c) {
        return -1;
    }
    int p=0 ,s=0;
    for (int i=0; i<r; i++) { // less optimized, O(n^2)
        for (int j=0; j<c; j++) {
            if (i == j) {
                p += arr[i][j];
            } else if (i+j == r-1) {
                s += arr[i][j];
            }
        }
    }
    return p+s;
}

int sum_of_diagonal(int arr[][3], int r) { // O(n) time complexity
    int sum = 0;
    for (int i=0; i<r; i++) {
        sum += arr[i][i];
        
        if (i != r-1-i) { // because for sec diagonal, (i = 0, 1, 2) and (j = 2, 1, 0). so j = r-1-i for sec diag 
            sum += arr[i][r-1-i];
        }
    }
    return sum;
}

int main() {
	int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	cout << "Max row sum = " << maxcol(mat, 3, 3) << endl;
	cout << "Sum of both diagonals = " << sum_of_diagonal(mat, 3);
	
	// 2D vectors -> better than arrays
	vector<vector<int>> matrix = {{1, 2}, {3, 4, 5}}; // Dynamic
	// Can have different sized rows
	// matrix.size() = no of rows
	// matrix[i].size() = no of columns for a row
	
	return 0;
}