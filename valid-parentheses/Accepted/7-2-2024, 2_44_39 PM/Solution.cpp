// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s.length()%2!=0) return false;
        for(int i= 0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{' || st.empty() || (s[i]=='}' && st.top()!='{') || (s[i]==')' && st.top()!='(') || (s[i]==']' && st.top()!='[') )
            {
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        return st.empty();
    }
};