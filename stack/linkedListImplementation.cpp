#include <iostream>
using namespace std;

class node {
public:
    int val;
    node* next;

    node(int val) {
        this->val = val;
        next = NULL;
    }
};
class stack {
public:
    node* head;
    int size;
    stack(){
        head=NULL;
        size=0;

    }
    void push(int val){
    node* temp= new node(val);
    temp->next=head;
    head=temp;
    size++;
}
void pop(){
    if(!head){
        cout<<"stack is Empty";
        return;
    }

    head=head->next;
    size--;
}

int top(){
     if(!head){
        cout<<"stack is Empty";
        return -1;
    }
    return head->val;
}

void display(){
node* temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout << endl;
    }
//reverse display
void print(node* temp){
    if(temp==NULL) return;
    print(temp->next);
    cout<<temp->val<<" ";
}
void display2(){
    node* temp=head;
    print(temp);
    cout<<endl;
}

};

int main() {
    stack st;
    cout << st.top() << endl;
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.pop();
    cout << st.top() << endl;
    st.display();
    cout<<"Stack in reverse order:"<<endl;
    st.display2();


    return 0;
}
