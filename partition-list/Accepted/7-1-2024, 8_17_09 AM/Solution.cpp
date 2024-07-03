// https://leetcode.com/problems/partition-list


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lowerElements=new ListNode(-1);
        ListNode* higherElements=new ListNode(-1);
        ListNode* tempLo=lowerElements;
        ListNode* tempHi=higherElements;
        ListNode* temp = head;
        while(temp!=NULL){
           if(temp->val<x){
            tempLo->next=temp;
            temp=temp->next;
            tempLo=tempLo->next;
           } 
           else{
            tempHi->next=temp;
            temp=temp->next;
            tempHi=tempHi->next;
           }

        }
        tempLo->next=higherElements->next;
        tempHi->next=NULL;
        return lowerElements->next;

        

    }
};