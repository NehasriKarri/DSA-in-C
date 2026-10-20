#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 5000
#define MAX_WORD_LEN 31

// Simple custom hash map entry for string frequencies
typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordMap;

// Helper to find or add word in map array
int getWordIndex(WordMap* map, int* mapSize, const char* word) {
    for (int i = 0; i < *mapSize; i++) {
        if (strcmp(map[i].word, word) == 0) {
            return i;
        }
    }
    // Add new word to map
    strcpy(map[*mapSize].word, word);
    map[*mapSize].count = 0;
    (*mapSize)++;
    return (*mapSize) - 1;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if (s == NULL || words == NULL || wordsSize == 0) {
        return NULL;
    }

    int sLen = strlen(s);
    int wordLen = strlen(words[0]);
    int totalLen = wordLen * wordsSize;

    if (sLen < totalLen) {
        return NULL;
    }

    // Allocate result array
    int* result = (int*)malloc(sLen * sizeof(int));

    // Build word frequency target table
    WordMap targetMap[MAX_WORDS];
    int mapSize = 0;
    int targetFreq[MAX_WORDS] = {0};

    for (int i = 0; i < wordsSize; i++) {
        int idx = getWordIndex(targetMap, &mapSize, words[i]);
        targetFreq[idx]++;
    }

    // Run sliding window offset by wordLen
    for (int offset = 0; offset < wordLen; offset++) {
        int left = offset;
        int right = offset;
        int count = 0;
        int currentFreq[MAX_WORDS] = {0};

        while (right + wordLen <= sLen) {
            // Extract word from right boundary
            char sub[MAX_WORD_LEN];
            strncpy(sub, s + right, wordLen);
            sub[wordLen] = '\0';
            right += wordLen;

            // Check if extracted word is in target vocabulary
            int idx = -1;
            for (int i = 0; i < mapSize; i++) {
                if (strcmp(targetMap[i].word, sub) == 0) {
                    idx = i;
                    break;
                }
            }

            if (idx != -1) {
                currentFreq[idx]++;
                count++;

                // If word frequency exceeds target, shrink left boundary
                while (currentFreq[idx] > targetFreq[idx]) {
                    char leftSub[MAX_WORD_LEN];
                    strncpy(leftSub, s + left, wordLen);
                    leftSub[wordLen] = '\0';

                    for (int i = 0; i < mapSize; i++) {
                        if (strcmp(targetMap[i].word, leftSub) == 0) {
                            currentFreq[i]--;
                            break;
                        }
                    }
                    count--;
                    left += wordLen;
                }

                // Match found
                if (count == wordsSize) {
                    result[(*returnSize)++] = left;
                }
            } else {
                // Invalid word: reset window state
                memset(currentFreq, 0, sizeof(currentFreq));
                count = 0;
                left = right;
            }
        }
    }

    return result;
}
