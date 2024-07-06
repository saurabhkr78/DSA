#include <iostream>
#include <stack>
using namespace std;

int operation(int val1, int val2, char ch) {
    if (ch == '+') return val1 + val2;
    else if (ch == '-') return val1 - val2;
    else if (ch == '*') return val1 * val2;
    else return val1 / val2;
}

int main() {
    string s = "79+4*8/3-"; // Postfix notation for "7 + 9 * 4 / 8 - 3"
    stack<int> val;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            val.push(s[i] - '0');
        } else {
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            int ans = operation(val1, val2, s[i]);
            val.push(ans);
        }
    }

    cout << val.top() << endl;
    // to confirm answer
    cout << (7 + 9) * 4 / 8 - 3 << endl;

    return 0;
}
