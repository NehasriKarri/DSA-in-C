#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    // Pointer for the position of unique elements
    int k = 1;

    // Traverse array starting from the second element
    for (int i = 1; i < numsSize; i++) {
        // If current element is different from the previous unique element
        if (nums[i] != nums[k - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}
