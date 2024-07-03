// https://leetcode.com/problems/intersection-of-two-linked-lists

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //find len of list
      ListNode* temp1=headA;
      ListNode* temp2=headB;  
      int lenA=0;
       while(temp1!=NULL){
        lenA++;
        temp1=temp1->next;
       }
       int lenB=0;
       while(temp2!=NULL){
        lenB++;
        temp2=temp2->next;
       }  
       temp1=headA;
       temp2=headB;
       if(lenA>lenB){
        int diff=(lenA-lenB);
        for(int i=1;i<=diff;i++){
            temp1=temp1->next;
        }
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
       }

       else{
        int diff=(lenB-lenA);
        for(int i=1;i<=diff;i++){
            temp2=temp2->next;
        }
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
       }
    }
};