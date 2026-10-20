#include <stdlib.h>

// Comparison function required for qsort
int compare(const void* a, const void* b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    // Sort the array using standard library qsort
    qsort(nums, numsSize, sizeof(int), compare);
    
    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; ++i) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            // Update closest if the current sum is closer to target
            if (abs(sum - target) < abs(closest - target)) {
                closest = sum;
            }

            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                return target; // If an exact match is found, return immediately
            }
        }
    }

    return closest;
}
