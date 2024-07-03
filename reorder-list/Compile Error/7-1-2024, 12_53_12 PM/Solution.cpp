// https://leetcode.com/problems/reorder-list

/*1.palindromeLL
2.merger 2sorted array
3.farzi node

 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        //right middle
        // while(fast!=NULL&&fast->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        //left middle
         while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            //now we to reverse slow->next
            ListNode* b=reverse(slow->next);
            //comarison using two pointer
            ListNode* a=head;
            slow->next=NULL;//for breakking the lists
            //merger a and b alternstively
            ListNode* =new ListNode(-1);
            ListNode* tempC=temp;
            ListNode* tempC=temp;


    }
};