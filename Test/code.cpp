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
    //delete
    void deleteAtEnd(){
        if(size==0){
            cout<<"List is Empty"<<endl; return;
        } 
        else if(size==1){
            head=tail=NULL;
            size--;
            return;
        }
        else {
            node* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            delete tail;
            tail=temp;
            tail->next=NULL;
            size--;
        }
    }
void deleteAtBeginning(){
        if(size==0) cout<<"List is empty"<<endl;
        else if(size==1){
            head=tail=NULL;
            size--;
    }
    else{
        head=head->next;
        size--;
    }
}
void deleteAtIdx(int idx){
    if(idx==0||idx>size) {
        cout<<"Invalid Index"<<endl;return;
    }
    else if(idx==0) return deleteAtBeginning();
    else if(idx==size) return deleteAtEnd();
    else{
        node* temp=head;
        for(int i=1;i<idx-1;i++){
            temp->next=temp->next->next;
            size--;
        }
    }

}
int  getIndexVal(int idx){
    if(idx==0|| idx>=size){
        cout<<"Invalid Index"<<endl;
        return -1;
    }
    else if(idx==0) return head->val;
    else if(idx==size-1) return tail->val;
    else{
        node* temp=head;
        for(int i=1;i<size;i++){
        temp=temp->next;
    }
    return temp->val;
}

//display
void display(){
if head==NULL return;
else{
while(temp!=NULL){
node* temp=head;
cout<<temp->val<<" ";
temp=temp->next
}
cout<<endl;
}
}

};

int main(){
    ll l;
    l.insertAtEnd(5);
}
