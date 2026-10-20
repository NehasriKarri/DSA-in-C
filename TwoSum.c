#include <stdlib.h>

// Define a structure for the hash table node
typedef struct HashNode {
    int key;              // The number from nums array
    int value;            // Its index
    struct HashNode* next;
} HashNode;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for the result array [index1, index2]
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // Choose a hash table size (using a prime or larger than numsSize)
    int tableSize = numsSize * 2 > 1024 ? numsSize * 2 : 1024;
    HashNode** table = (HashNode**)calloc(tableSize, sizeof(HashNode*));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        // Calculate hash index for the complement (handling negative numbers)
        int h = complement % tableSize;
        if (h < 0) h += tableSize;

        // Search for the complement in the hash table
        HashNode* curr = table[h];
        int found = 0;
        while (curr != NULL) {
            if (curr->key == complement) {
                result[0] = curr->value;
                result[1] = i;
                found = 1;
                break;
            }
            curr = curr->next;
        }

        if (found) {
            break; // Pair found, exit loop
        }

        // Insert current number and its index into the hash table
        int insert_h = nums[i] % tableSize;
        if (insert_h < 0) insert_h += tableSize;

        HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
        newNode->key = nums[i];
        newNode->value = i;
        newNode->next = table[insert_h];
        table[insert_h] = newNode;
    }

    // Clean up allocated hash table memory to prevent leaks
    for (int i = 0; i < tableSize; i++) {
        HashNode* curr = table[i];
        while (curr != NULL) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(table);

    return result;
}
