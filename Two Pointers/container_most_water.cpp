/*You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j=n-1;
        int area = INT_MIN;
        while (i < j) {
            int h = min(height[i], height[j]);
            area = max(area, (j-i)*h);
            if (h == height[i]) {
                i++;
            } else {
                j--;
            }
        }
        return area;
    }
};

// Important points
// Time complexity: O(n) as we traverse the array once.
// Space complexity: O(1) as we are using constant space to store the pointers and not using any extra space.
// Greedy approach: We are using two pointers to find the maximum area. 
// We start with the leftmost and rightmost lines and calculate the area. 
// Then we move the pointer pointing to the shorter line towards the other pointer, as moving the taller line will not increase the area. 
// We repeat the process until the two pointers meet.