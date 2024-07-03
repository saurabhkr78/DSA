// https://leetcode.com/problems/remove-nth-node-from-end-of-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* slow=head;  
      ListNode* fast=head;
      //traverse n+1 steps
      for(int i=0;i<=n;i++){
        if(fast==NULL) return head->next;
        fast=fast->next;
      }
      //move slow and fast at same pace
      while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;

      }
      //now slow is exactly at the left of the node which is to be deleted from the end
      slow->next=slow->next->next;
      return head;
    }
};