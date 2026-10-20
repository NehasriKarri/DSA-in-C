#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array to optimize the binary search range
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size, n = nums2Size;
    int low = 0, high = m;

    while (low <= high) {
        int i = low + (high - low) / 2;
        int j = (m + n + 1) / 2 - i;

        int left1  = (i == 0) ? INT_MIN : nums1[i - 1];
        int right1 = (i == m) ? INT_MAX : nums1[i];
        int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
        int right2 = (j == n) ? INT_MAX : nums2[j];

        if (left1 <= right2 && left2 <= right1) {
            // If total length is odd, return the maximum of the left partitions
            if ((m + n) % 2 == 1) {
                return (double)(left1 > left2 ? left1 : left2);
            }
            // If total length is even, return the average of max(left) and min(right)
            int maxLeft = (left1 > left2) ? left1 : left2;
            int minRight = (right1 < right2) ? right1 : right2;
            return (double)(maxLeft + minRight) / 2.0;
        }

        if (left1 > right2) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }

    return 0.0;
}
