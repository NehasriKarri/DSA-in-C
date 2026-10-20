#include <string.h>

int romanToInt(char* s) {
    int total = 0;
    int prevValue = 0;
    int n = strlen(s);

    // Traverse the string from right to left
    for (int i = n - 1; i >= 0; i--) {
        int currValue = 0;
        
        // Map character to its integer value
        switch (s[i]) {
            case 'I': currValue = 1; break;
            case 'V': currValue = 5; break;
            case 'X': currValue = 10; break;
            case 'L': currValue = 50; break;
            case 'C': currValue = 100; break;
            case 'D': currValue = 500; break;
            case 'M': currValue = 1000; break;
        }

        // If current value is less than the previous one, subtract it (e.g., IV, IX)
        if (currValue < prevValue) {
            total -= currValue;
        } else {
            total += currValue;
        }
        
        prevValue = currValue;
    }

    return total;
}
