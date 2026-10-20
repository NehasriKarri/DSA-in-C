#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Helper function for recursive matching with memoization
bool dpMatch(char* s, char* p, int i, int j, int m, int n, int** memo) {
    if (j == n) {
        return i == m;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    bool firstMatches = (i < m && (p[j] == s[i] || p[j] == '.'));
    bool result = false;

    if (j + 1 < n && p[j + 1] == '*') {
        result = dpMatch(s, p, i, j + 2, m, n, memo) || 
                 (firstMatches && dpMatch(s, p, i + 1, j, m, n, memo));
    } else {
        result = firstMatches && dpMatch(s, p, i + 1, j + 1, m, n, memo);
    }

    memo[i][j] = result ? 1 : 0;
    return result;
}

bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);

    // Allocate and initialize a 2D memoization table with -1
    int** memo = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        memo[i] = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            memo[i][j] = -1;
        }
    }

    bool ans = dpMatch(s, p, 0, 0, m, n, memo);

    // Clean up allocated memory to prevent leaks
    for (int i = 0; i <= m; i++) {
        free(memo[i]);
    }
    free(memo);

    return ans;
}
