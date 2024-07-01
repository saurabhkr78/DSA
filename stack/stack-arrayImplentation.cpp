#include<iostream>
using namespace std;
class Stack{//udds
public:
int arr[5];
int idx=-1;
void push(int val){
    if(idx==sizeof(arr)){ cout<<"stack is Full";
     return;
     }
    idx++;
    arr[idx]=val;
}
void pop(){
    if(idx==-1){
        cout<<"stack is Empty";
        return;
    }

    idx--;
}
int top(){
    if(idx==-1){
        cout<<"stack is Empty"<<endl;
        return -1;
    }
    return arr[idx];
}
int size(){
    return idx+1;
}
void display(){
for(int i=0;i<=idx;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}

};


int main(){

    Stack st;
    cout<<st.top()<<endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    st.display();



    
}