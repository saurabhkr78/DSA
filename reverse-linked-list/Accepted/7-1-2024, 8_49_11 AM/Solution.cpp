// https://leetcode.com/problems/reverse-linked-list


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL,*curr=head,*Next=NULL;
    
        
        while(curr){
            //preserve list
           Next = curr->next;
           //to break link
           curr->next=prev;
           prev=curr;
           curr=Next;
        }
        return prev;

    }
};