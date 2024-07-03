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
      for(int i=1;i<=n+1;i++){
        if(fast==NULL) return NULL;
        else fast=fast->next;
      }
      while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;

      }
      slow->next=slow->next->next;
      return head;
    }
};