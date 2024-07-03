// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
    for(int i=0;i<s.length();i++){

        if(s[i]=='('||s[i]=='{'||s[i]=='[') st.push(s[i]);

        else{
            //if nothing is being pushed to stack
            if(st.size()==0) return false;
            char top=st.top();
            st.pop();
            if ((s[i] == ')' && top != '(') ||
                    (s[i] == '}' && top != '{') ||
                    (s[i] == ']' && top != '[')) {
                    return false;
                }

        }
    }
    if(st.size()==0) return true;
        else return false;    
    }
    

};