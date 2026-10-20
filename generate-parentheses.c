#include <stdlib.h>
#include <string.h>

void backtrack(char*** result, int* returnSize, int* capacity, char* current, int open, int close, int n) {
    // If the combination is complete, add it to our result array
    if (open == n && close == n) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = (char**)realloc(*result, (*capacity) * sizeof(char*));
        }
        
        // Allocate and copy the current valid combination
        (*result)[*returnSize] = (char*)malloc((2 * n + 1) * sizeof(char));
        strcpy((*result)[*returnSize], current);
        (*returnSize)++;
        return;
    }

    int idx = open + close;

    // Try adding an opening parenthesis if we haven't reached the limit
    if (open < n) {
        current[idx] = '(';
        current[idx + 1] = '\0';
        backtrack(result, returnSize, capacity, current, open + 1, close, n);
    }

    // Try adding a closing parenthesis if it won't violate validity
    if (close < open) {
        current[idx] = ')';
        current[idx + 1] = '\0';
        backtrack(result, returnSize, capacity, current, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    int capacity = 16;
    char** result = (char**)malloc(capacity * sizeof(char*));
    
    // Allocate buffer to build combinations in-place
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));
    current[0] = '\0';

    backtrack(&result, returnSize, &capacity, current, 0, 0, n);

    free(current);
    return result;
}
