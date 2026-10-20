#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Create a dummy node on the stack to simplify result list building
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    
    struct ListNode* tail = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        // Allocate memory for the new node in C
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        tail->next = newNode;
        tail = tail->next;
        
        carry = sum / 10;
    }

    return dummy.next;
}
