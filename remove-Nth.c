#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Initialize a dummy node on the stack to handle edge cases cleanly
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    // Advance the fast pointer by n steps
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }

    // Move both pointers until fast reaches the last node
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Unlink and free the target node
    struct ListNode* target = slow->next;
    slow->next = slow->next->next;
    free(target);

    return dummy.next;
}
