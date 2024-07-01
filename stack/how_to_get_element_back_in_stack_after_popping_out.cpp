#include <iostream>
#include<stack>
using namespace std;

int main(){

    stack<int>st;
    stack<int> temp;
    cout<<st.size()<<endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    while(st.size()>0){
        cout<<st.top()<<" ";
        temp.push(st.top());//Push the element to the temp stack
        st.pop();
    }
    //if you want to restore the original stack
    while(temp.size()>0){
        cout<<st.top()<<" ";
        st.push(temp.top());
        temp.pop();

    }


}