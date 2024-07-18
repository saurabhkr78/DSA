#include <iostream>
#include<stack>
#define MAX_SIZE 7
long long stacksize=MAX_SIZE;
using namespace std;

int main(){

    stack<int>st;
    if(st.size()==0) cout<<"stack is empty"<<endl;
    
    cout<<st.size()<<endl;
    
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.push(80);
    cout<<st.size()<<endl;

    if(st.size()<=stacksize)cout<<"stack is not full"<<endl;
    else cout<<"stack is full"<<endl;

    st.pop();

    cout<<st.size()<<endl;

    cout<<st.top()<<endl;
    
    while(st.size()>0){
        cout<<st.top()<<" ";
        st.pop();
    }


}