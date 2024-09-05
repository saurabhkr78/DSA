/*
Given a string s, you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings.

Example 1:

Input:
s = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C



*/
#include<iostream>
using namespace std;
void solve(string ip,string op){
    if(ip.length()==0){ cout<<op;//base condition
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back(" ");
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1);
    solve(ip,op2);



}
int main(){
    string ip;
    cin>>ip;
    string op="";
    op.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op);



}