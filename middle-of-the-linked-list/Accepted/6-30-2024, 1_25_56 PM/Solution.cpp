// https://leetcode.com/problems/middle-of-the-linked-list

class Solution {
public:
ListNode* midElement(ListNode* head,int m_idx){
    ListNode* mid=head;
    for(int i=0;i<m_idx;i++){
        mid=mid->next;

    }
    return mid;
}
    ListNode* middleNode(ListNode* head) {
       int len=0;
       ListNode* tmp=head;
       while(tmp!=NULL){
        len++;
        tmp=tmp->next;
       } 
       int m_idx=len/2;
    return midElement(head,m_idx);
    }
};