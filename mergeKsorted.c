#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Swap two ListNode pointers
void swap(struct ListNode** a, struct ListNode** b) {
    struct ListNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Min-Heapify downwards
void heapifyDown(struct ListNode** heap, int size, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[left]->val < heap[smallest]->val)
        smallest = left;
    if (right < size && heap[right]->val < heap[smallest]->val)
        smallest = right;

    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Min-Heapify upwards
void heapifyUp(struct ListNode** heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[idx]->val < heap[parent]->val) {
            swap(&heap[idx], &heap[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0 || lists == NULL) return NULL;

    // Allocate memory for the heap array
    struct ListNode** heap = (struct ListNode**)malloc(listsSize * sizeof(struct ListNode*));
    int heapSize = 0;

    // Push non-empty list heads into the min-heap
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            heap[heapSize] = lists[i];
            heapifyUp(heap, heapSize);
            heapSize++;
        }
    }

    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;

    // Extract min and push next node until heap is empty
    while (heapSize > 0) {
        struct ListNode* node = heap[0];

        tail->next = node;
        tail = node;

        if (node->next != NULL) {
            heap[0] = node->next;
            heapifyDown(heap, heapSize, 0);
        } else {
            heap[0] = heap[heapSize - 1];
            heapSize--;
            if (heapSize > 0) {
                heapifyDown(heap, heapSize, 0);
            }
        }
    }

    free(heap);
    return dummy.next;
}
