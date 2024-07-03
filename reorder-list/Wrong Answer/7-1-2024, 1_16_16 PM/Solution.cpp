// https://leetcode.com/problems/reorder-list

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = NULL;

        while (curr) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // right middle
        // while(fast!=NULL&&fast->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        // left middle
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // now we to reverse slow->next
            ListNode* b = reverse(slow->next);
            // comparison using two pointer
            ListNode* a = head;
            slow->next = NULL; // for breaking the lists
            // merger a and b alternately
            ListNode* c = new ListNode(-1);
            ListNode* tempC = c;
            ListNode* tempA = a;
            ListNode* tempB = b;
            while (tempA && tempB) { // tempA!=NULL
                // for a
                tempC->next = tempA;
                tempA = tempA->next;
                tempC = tempC->next;

                // for b
                tempC->next = tempB;
                tempB = tempB->next;
                tempC = tempC->next;
            }
            tempC->next = tempA;
            head = c->next; // to remove link from farzi node
        }
    }
};
