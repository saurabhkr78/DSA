/*1.If opening bracket in string keep push it in stack.
2. If closing bracket in string then peek at top of stack and if opening bracket is found at top then pop out that opening bracket
3. after this,if stack size is empty then true;*/

#include<iostream>
#include<stack>
using namespace std;
bool isBalanced(string s){
    stack<char>st;
    for(int i=0;i<s.length();i++){

        if(s[i]=='(') st.push(s[i]);

        else{
            //if nothing is being pushed to stack
            if(st.size()==0) return false;
            st.pop();

        }
        
        

    }
    if(st.size()==0) return true;
        else return false;
}




int main(){
    string s="(()()())";
    string s1="))))";
    cout<<isBalanced(s)<<endl;
    cout<<isBalanced(s1)<<endl;

}