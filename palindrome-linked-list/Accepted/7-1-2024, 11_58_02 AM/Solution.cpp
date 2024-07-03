// https://leetcode.com/problems/palindrome-linked-list

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

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) // If the list is empty or has only one node
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle of the linked list using fast and slow pointers
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list starting from slow->next
        ListNode* secondHalf = reverse(slow->next);
        ListNode* firstHalf = head;

        // Compare the first half and the reversed second half
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
