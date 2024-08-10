class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return head;
        if (n == 0)
            return head;

    // Step 1: Calculate the length of the linked list
        int length = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            length++;
            curr = curr->next;
        }
    // Step 2: Check if we need to remove the head
        if (length == n) {
            curr = head->next;
            return curr;
        }
    // Step 3: Find the position of the node to remove
        curr = head;
        int changeFrom = length - n;
        int count = 1;
        while (count < changeFrom && curr != NULL) {
            curr = curr->next;
            count++;
        }
        curr->next = curr->next->next;
        return head;
    }
};