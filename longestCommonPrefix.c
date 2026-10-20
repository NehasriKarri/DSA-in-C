#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    // Scan character by character through the first string
    for (int i = 0; strs[0][i] != '\0'; i++) {
        char c = strs[0][i];
        
        // Compare with the same position in all other strings
        for (int j = 1; j < strsSize; j++) {
            // If we hit the end of another string or find a character mismatch
            if (strs[j][i] == '\0' || strs[j][i] != c) {
                // Allocate memory for the prefix found so far (+1 for null-terminator)
                char* result = (char*)malloc((i + 1) * sizeof(char));
                strncpy(result, strs[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }

    // If the entire first string is a common prefix for all strings
    int len = strlen(strs[0]);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    strcpy(result, strs[0]);
    
    return result;
}
