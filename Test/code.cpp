#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node(int val){//initalising the variables of class using constructor
        this->val=val;
        this->next=NULL;
    }
};
class ll{
    public:
    node* head;
    node* tail;
    int size;
    ll(){//initalising the variables of class using constructor
        head=tail=NULL;
        size=0;
    }
    void insertAtEnd(int val){
        node* temp=new node(val);
        if (size==0) head=tail=temp;
        else{ 
            tail->next=temp;
            tail=temp;
        }
        size++;

    }
    void insertAtBeginning(int val){
        node* temp=new node(val);
        if (size==0) head=tail=temp;
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void insertAtIdx(int val,int idx){
        if(idx<0||idx>0) cout<<"Invalid Index Input"<<endl;
        if (idx==0)  return insertAtBeginning(val);
        if (idx==size) return insertAtEnd(val);
        else {
            node* temp=new node(val);
            //to traverse the LL
            node* x=head;
            for(int i=1;i<idx-1;i++){
                x=x->next;
            }
            temp->next=x->next;
            x->next=temp;
            size++;
        }
    }
};

int main(){
    ll l;
    l.insertAtEnd(5);
}
