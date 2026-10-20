#include <stdbool.h>

bool isPalindrome(int x) {
    // Negative numbers and numbers ending in 0 (except 0 itself) are not palindromes
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedHalf = 0;
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    // If the length is even, x equals reversedHalf.
    // If the length is odd, we can drop the middle digit by doing reversedHalf / 10.
    return x == reversedHalf || x == reversedHalf / 10;
}
