/*
Rule:if s[i] is a digit then push in val stack
if s[i] is a operator then 
a)if Operator stack is empty then push
b) if s[i] is a bracket then push
c) if op.top()=='(' push
d) if (s[i]==')') then 
     char ch=operator  stack's top element
    int val 2=val stack top element
    int val 1=val stack next top element
    int ans= val1 ch val2  till you hit an '(';
    pop the op.top() i.e '('
e)if priority(st.top)<priority(s[i]) then push
f)while priority(st.top)>=priority(s[i]) then logic
    char ch=operator  stack's top element
    int val 2=val stack top element
    int val 1=val stack next top element
    int ans= val1 ch val2

*/
#include<iostream>
#include<stack>
using namespace std;
int priority(char ch){
    if(ch=='+'|| ch=='-') return 1; 
    else return 2;
}
int operation(int val1,int val2,char ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else return val1/val2;
}
int main(){
    string s="(7+9)*4/8-3";
    stack<int>val;
    stack<char>op;
    for(int i=0;i<s.length();i++){
        if(s[i]>=48&&s[i]<=57){
            val.push(s[i]-48);
        }
        else{
            if(op.empty()) op.push(s[i]) ;
            else if(s[i]=='(') op.push(s[i]) ;
            else if(op.top()=='(') op.push(s[i]) ;
            
            else if(s[i]==')'){
                while(op.top()!='('){
                    char ch=op.top();
                op.pop();
                int val2=val.top();
                val.pop();
                int val1=val.top();
                val.pop();
                int ans=operation(val1,val2,ch);
                val.push(ans);
                }
                op.pop();
            }
            else if(priority(s[i])>priority(op.top())) op.push(s[i]) ;

           else {

            while(op.size()>0&&priority(s[i])<=priority(op.top())){
                char ch=op.top();
                op.pop();
                int val2=val.top();
                val.pop();
                int val1=val.top();
                val.pop();
                int ans=operation(val1,val2,ch);
                val.push(ans);
            }
            op.push(s[i]);
           }
        }
        
    }
    //the op stack can still have some value left so
    while(op.size()>0){
         char ch=op.top();
                op.pop();
                int val2=val.top();
                val.pop();
                int val1=val.top();
                val.pop();
                int ans=operation(val1,val2,ch);
                val.push(ans);
    }
    cout<<val.top()<<endl;
    // to confirm answer
    cout<<(7+9)*4/8-3;

}