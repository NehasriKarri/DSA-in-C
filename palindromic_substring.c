#include <string.h>
#include <stdlib.h>

// Helper function to expand around the center
void expand(char* s, int left, int right, int n, int* start, int* bestLength) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }

    int length = right - left - 1;
    if (length > *bestLength) {
        *bestLength = length;
        *start = left + 1;
    }
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";

    int start = 0;
    int bestLength = 1;

    for (int i = 0; i < n; i++) {
        // Odd length palindromes (single character center)
        expand(s, i, i, n, &start, &bestLength);
        // Even length palindromes (two character center)
        expand(s, i, i + 1, n, &start, &bestLength);
    }

    // Allocate memory for the result substring + null terminator
    char* result = (char*)malloc((bestLength + 1) * sizeof(char));
    
    // Copy the substring into the newly allocated memory
    strncpy(result, s + start, bestLength);
    result[bestLength] = '\0'; // Null-terminate the string

    return result;
}
