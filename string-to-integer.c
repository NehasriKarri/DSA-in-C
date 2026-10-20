#include <limits.h>
#include <string.h>

int myAtoi(char* s) {
    int i = 0;
    int n = strlen(s);

    // 1. Skip leading whitespaces
    while (i < n && s[i] == ' ') {
        i++;
    }

    // 2. Handle optional sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // 3. Convert digits and handle overflow/underflow
    int value = 0;
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';
        int lastAllowedDigit = (sign == 1) ? 7 : 8;

        if (value > INT_MAX / 10 || 
            (value == INT_MAX / 10 && digit > lastAllowedDigit)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        // 2147483648 is valid only as the magnitude of INT_MIN.
        if (sign == -1 && value == INT_MAX / 10 && digit == 8) {
            return INT_MIN;
        }

        value = value * 10 + digit;
        i++;
    }

    return sign * value;
}
