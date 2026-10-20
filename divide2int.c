#include <limits.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    // Handle 32-bit signed integer overflow edge case
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determine the sign of the result
    int negative = (dividend < 0) ^ (divisor < 0);

    // Convert numbers to long long to prevent overflow when taking absolute values
    long long absDividend = llabs((long long)dividend);
    long long absDivisor = llabs((long long)divisor);

    long long quotient = 0;

    // Bitwise shift approach: subtract large powers of 2 multiples of divisor
    while (absDividend >= absDivisor) {
        long long tempDivisor = absDivisor;
        long long multiple = 1;

        // Double tempDivisor and multiple until it exceeds absDividend
        while (absDividend >= (tempDivisor << 1)) {
            tempDivisor <<= 1;
            multiple <<= 1;
        }

        absDividend -= tempDivisor;
        quotient += multiple;
    }

    // Apply sign and return
    return negative ? -quotient : quotient;
}
