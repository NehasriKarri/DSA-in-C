#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // Pointer for non-val elements

    for (int i = 0; i < numsSize; i++) {
        // If current element is not equal to val, write it to index k
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k; // k is the count of valid elements
}
