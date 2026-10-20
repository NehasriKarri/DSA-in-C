#include <stdlib.h>

// Comparison function required for qsort
int compare(const void* a, const void* b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3) return NULL;

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 16; // Initial capacity for our dynamic result array
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; ++i) {
        // Skip duplicate elements for the first number
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        // If the smallest number is greater than 0, no sum can be 0
        if (nums[i] > 0) break;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                // Resize result arrays if capacity is reached
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                // Allocate and store the valid triplet
                int* triplet = (int*)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];

                result[*returnSize] = triplet;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                int leftVal = nums[left];
                int rightVal = nums[right];
                // Skip duplicates for the second and third numbers
                while (left < right && nums[left] == leftVal) left++;
                while (left < right && nums[right] == rightVal) right--;
            }
        }
    }

    return result;
}
