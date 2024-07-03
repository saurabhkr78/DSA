// https://leetcode.com/problems/rotate-list

/*find length of list
if temp->next=NULL then tail=temp;
k=k%length
set temp at(n-k)th post by traversing
connect tail->next=head in order to connect LL tail with head
now,new head will be temp->next because LL head starts from here
finally make temp->next=Null to make it tail of LL
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int n=0;
        ListNode* temp=head;
        ListNode* tail=NULL;

        while(temp!=NULL){
            if(temp->next==NULL) tail=temp;
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0) return head;
        temp=head;
        for(int i=1;i<n-k;i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;

        return head;

    }
};