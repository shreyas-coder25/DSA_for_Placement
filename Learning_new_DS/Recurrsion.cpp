#include <bits/stdc++.h>
using namespace std;

// Fibonacci series 
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
// Time complexity: O(2^n)
// Space complexity: O(n) due to the recursion stack

// Check if array is sorted
bool issorted(vector<int> arr, int n) {
    if (n <= 1) {
        return true;
    }
    if (arr[n - 1] < arr[n - 2]) {
        return false;
    }
    return issorted(arr, n - 1);
}
// Time complexity: O(n)
// Space complexity: O(n) due to the recursion stack

// Binary Search
int bin(vector<int> &arr, int t, int s, int e) {
    int m = (s+e)/2;
    if (arr[m] == t) {
        return m;
    } else if (arr[m] > t) {
        return bin(arr, t, s, m-1);
    } else {
        return bin(arr, t, m+1, e);
    }
    return -1;
}
// Time complexity: O(log n)
// Space complexity: O(log n) due to the recursion stack
