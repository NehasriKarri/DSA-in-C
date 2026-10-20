#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    
    // Edge cases where no conversion is needed
    if (numRows == 1 || numRows >= len) {
        char* result = (char*)malloc(len + 1);
        strcpy(result, s);
        return result;
    }

    // Allocate memory for the final result string + null terminator
    char* result = (char*)malloc(len + 1);
    int idx = 0;
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += cycleLen) {
            // Add the main character for this row in the current cycle
            result[idx++] = s[j + i];
            
            // Add the diagonal character (only for intermediate rows)
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < len) {
                result[idx++] = s[j + cycleLen - i];
            }
        }
    }

    result[idx] = '\0'; // Null-terminate the string
    return result;
}
