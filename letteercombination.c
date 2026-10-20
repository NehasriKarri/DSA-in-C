#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);
    if (len == 0) {
        return NULL;
    }

    const char* mapping[] = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    // Start with a base array containing an empty string
    int currentSize = 1;
    char** result = (char**)malloc(sizeof(char*));
    result[0] = (char*)malloc(1);
    result[0][0] = '\0';

    for (int i = 0; i < len; i++) {
        int digit = digits[i] - '0';
        const char* candidateLetters = mapping[digit];
        int numLetters = strlen(candidateLetters);
        
        if (numLetters == 0) continue;

        int nextSize = currentSize * numLetters;
        char** nextResult = (char**)malloc(nextSize * sizeof(char*));
        int nextIndex = 0;

        // Expand existing combinations with each new letter
        for (int j = 0; j < currentSize; j++) {
            for (int k = 0; k < numLetters; k++) {
                // Allocate memory for the new combined string (current length + 1 new char + null terminator)
                nextResult[nextIndex] = (char*)malloc((i + 2) * sizeof(char));
                strcpy(nextResult[nextIndex], result[j]);
                nextResult[nextIndex][i] = candidateLetters[k];
                nextResult[nextIndex][i + 1] = '\0';
                nextIndex++;
            }
        }

        // Free the old result array and its strings to prevent memory leaks
        for (int j = 0; j < currentSize; j++) {
            free(result[j]);
        }
        free(result);

        result = nextResult;
        currentSize = nextSize;
    }

    *returnSize = currentSize;
    return result;
}
