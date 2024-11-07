# Lecture 1

## sol 1
```
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
```
# Lecture 2
## sol 1:
```
    ListNode* reverseList(ListNode* head) {
        // Initialize pointers
        ListNode* prev = nullptr; // Previous node starts as NULL
        ListNode* next = nullptr; // Next node
        ListNode* curr = head;    // Current node starts at the head

        // Traverse the list
        while (curr != nullptr) {
            // Save the next node
            next = curr->next;

            // Reverse the link
            curr->next = prev;

            // Move pointers forward
            prev = curr; // Move prev to the current node
            curr = next; // Move curr to the next node
        }

        // prev is now the new head of the reversed list
        return prev;
    }
```
## sol 2
```
 ListNode* middleNode(ListNode* head) {
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while (fastPointer != nullptr && fastPointer->next != nullptr) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        return slowPointer;
    }
```

# Lecture 3
## Sol 1:
```

bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }

        if(head->val == INT_MAX){
            return true;
        }

        head->val=INT_MAX;
        return hasCycle(head->next);
    }

```
## sol 2
```
int findLength(Node* slow, Node* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow!=fast){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;     
        fast = fast->next->next;
        if (slow == fast) {
            return findLength(slow, fast);
        }
    }

    // Step 3: If the fast pointer
    // reaches the end, there is no loop
    return 0; 
}
```
## sol 3
```
ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    
    ListNode *slow  = head;
    ListNode *fast  = head;
    ListNode *entry = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {                      
            while(slow != entry) {               
                slow  = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;      
    }
```
# lecture 4
## sol 1
```
void pairSum(struct Node *head, int x)  
{  
    // Set two pointers, first to the beginning of DLL  
    // and second to the end of DLL.  
    struct Node *first = head;  
    struct Node *second = head;  
    while (second->next != NULL)  
        second = second->next;  
  
    // To track if we find a pair or not  
    bool found = false;  
  
    // The loop terminates when two pointers  
    // cross each other (second->next  
    // == first), or they become same (first == second)  
    while (first != second && second->next != first)  
    {  
        // pair found  
        if ((first->data + second->data) == x)  
        {  
            found = true;  
            cout << "(" << first->data<< ", "
                << second->data << ")" << endl;  
  
            // move first in forward direction  
            first = first->next;  
  
            // move second in backward direction  
            second = second->prev;  
        }  
        else
        {  
            if ((first->data + second->data) < x)  
                first = first->next;  
            else
                second = second->prev;  
        }  
    }  
  
    // if pair is not present  
    if (found == false)  
        cout << "No pair found";  
}
```
## sol 2
```
ListNode* reverse(ListNode* head,int k,int len){
        if(k>len){
            return head;
        }
        int x=k;
        cout<<len<<endl;
        ListNode* temp=head;
        ListNode* join=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        while(x>0){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
            x--;
        }
        join->next=reverse(next,k,len-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
         int len=0;
         ListNode* temp=head;
         while(temp!=NULL){
             len++;
             temp=temp->next;
         }
         return reverse(head,k,len);
    }```
