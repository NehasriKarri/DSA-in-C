#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* previous = &dummy;

    while (previous->next != NULL && previous->next->next != NULL) {
        struct ListNode* first = previous->next;
        struct ListNode* second = first->next;

        // Perform the swap
        first->next = second->next;
        second->next = first;
        previous->next = second;

        // Move pointer forward for the next pair
        previous = first;
    }

    return dummy.next;
}
