// https://leetcode.com/problems/sort-list

class Solution {
public:
    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        //farzi node approach
      ListNode* c=new ListNode(-1);
      ListNode* temp=c;
      while(list1!=NULL&&list2!=NULL){
        if(list1->val<=list2->val){
            temp->next=list1;
            list1=list1->next;
            temp=temp->next;
        }
        else{
            temp->next=list2;
            list2=list2->next;
            temp=temp->next;
        }
      } 
      if(list1==NULL)temp->next=list2;
      else temp->next=list1;
      return c->next;
    }
    ListNode* sortList(ListNode* head) {
        //base case of recursion
        if(!head || !head->next) return head;
        //find left middle using fast and slow pointer
        ListNode* slow=head;
        ListNode* fast=head;
        //to find left middle
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //now slow is at the left middle now break the list into two halves
        ListNode* a=head;
        ListNode* b=slow->next;
        slow->next=NULL;
        //sortthe two list
        a = sortList(a);
        b = sortList(b);
        //merge sorted lists
        ListNode* c = mergeLists(a,b);
        return c;
    }
};