#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* groupPrev = &dummy;

    while (1) {
        // Find the k-th node from groupPrev
        struct ListNode* kth = groupPrev;
        for (int i = 0; i < k && kth != NULL; ++i) {
            kth = kth->next;
        }

        // If fewer than k nodes remain, leave them as-is
        if (kth == NULL) {
            break;
        }

        struct ListNode* groupNext = kth->next;
        struct ListNode* current = groupPrev->next;
        struct ListNode* previous = groupNext;

        // Reverse the k nodes
        while (current != groupNext) {
            struct ListNode* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        // Connect groupPrev to the newly reversed group
        struct ListNode* oldGroupStart = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = oldGroupStart;
    }

    return dummy.next;
}
