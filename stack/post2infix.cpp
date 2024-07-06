#include <iostream>
#include <stack>
using namespace std;

string operation(string val1, string val2, char ch) {
    string s="";
    s+=val1;
    s.push_back(ch);
    s+=val2;
    return s;
}

int main() {
    string s = "79+4*8/3-"; 
    stack<string> val;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            val.push(to_string(s[i] - '0'));
        } else {
            string val2 = val.top();
            val.pop();
            string val1 = val.top();
            val.pop();
            string ans = operation(val1, val2, s[i]);
            val.push(ans);
        }
    }

    cout << val.top() << endl;
    // to confirm answer
    cout << "7 + 9 * 4 / 8 - 3" << endl;

    return 0;
}
