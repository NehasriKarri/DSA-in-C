#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    if (s == NULL) return true;

    int n = strlen(s);
    if (n == 0) return true;

    char* stack = (char*)malloc(n * sizeof(char));
    if (stack == NULL) return false;

    int top = -1;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) {
                free(stack);
                return false;
            }

            char popped = stack[top--];
            if ((c == ')' && popped != '(') ||
                (c == '}' && popped != '{') ||
                (c == ']' && popped != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool result = (top == -1);
    free(stack);
    return result;
}
