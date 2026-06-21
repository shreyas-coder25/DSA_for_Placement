/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

Follow up: Can you come up with an algorithm that runs in O(m + n) time?*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        A.resize(m+n);
        int i=m-1, j=n-1, id=m+n-1;

        while (i>=0 && j>=0) {
            if (A[i] > B[j]) {
                A[id] = A[i];
                i--; id--;
            } else {
                A[id] = B[j];
                j--; id--;
            }
        }
        while (j >= 0) {
            A[id--] = B[j--];
        }
        return;
    }
};

// Important Notes

// Time Complexity: O(m+n) where m and n are the sizes of the two arrays. We are traversing both arrays once.
// Space Complexity: O(1) as we are not using any extra space for another array. We are modifying the first array in place.
// Other method: Sorting the combined array would take O((m+n)log(m+n)) time, which is less efficient than the above approach.