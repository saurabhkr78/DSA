#include <iostream>
using namespace std;

// Creating a user-defined data type
class node {
public:
    int val;
    node* next;

    // Constructor
    node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// User-defined data structure
class Queue {
public:
    node* head;
    node* tail;
    int size;

    Queue() {
        head = tail = NULL;
        size = 0;
    }
//insertAtEnd
    void push(int Val) {
        node* temp = new node(Val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
  
    //delete node at head
    void pop(){
        if(size==0){
            cout<<"Queue is empty";
            return;
            }
        if(size==1){
        //   head=tail=NULL;
        //   size--;
        node *temp= head;
            head=head->next;
            size--;
            delete(temp);
        }
        if(size>1){
            node *temp= head;
            head=head->next;
            size--;
            delete(temp);
        }
    }
   int front(){
    if(size==0){
            cout<<"Queue is empty";
            return -1;
            }
    else return head->val;
   }
    int back(){
    if(size==0){
            cout<<"Queue is empty";
            return -1;
            }
    else return tail->val;
   }

    // Print linked list in order
    void display() {
        node* temp = head;
        if (temp == NULL) return;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int length(){
        return size;
    }
    bool empty(){
        if(size==0) return true;
        else return false;
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    q.push(60);
    q.display();
    q.pop();
    q.display();
}