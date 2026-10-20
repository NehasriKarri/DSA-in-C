#include <string.h>

int strStr(char* haystack, char* needle) {
    int hLen = strlen(haystack);
    int nLen = strlen(needle);

    if (nLen > hLen) {
        return -1;
    }

    // Only search up to the index where needle can still fully fit
    for (int i = 0; i <= hLen - nLen; i++) {
        int j = 0;
        
        // Compare substring starting at index i
        while (j < nLen && haystack[i + j] == needle[j]) {
            j++;
        }

        // If all characters matched, return starting index
        if (j == nLen) {
            return i;
        }
    }

    return -1;
}
