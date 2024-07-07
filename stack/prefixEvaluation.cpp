//reverse traverse to solve
//pop val 1 then val 2
// rest post fix evaluation


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
    string s = "-/*+79483";
    stack<int> val;

    // Traverse the string from right to left
    for (int i = s.length() - 1; i >= 0; i--) {
        // If the character is a digit, push it to the stack
        if (s[i] >= '0' && s[i] <= '9') {
            val.push(s[i] - '0');
        }
        // If the character is an operator, pop two elements from the stack, perform the operation and push the result back to the stack
        else {
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            int ans = operation(val1, val2, s[i]);
            val.push(ans);
        }
    }

    // The top element of the stack is the result
    cout << "Prefix evaluation result: " << val.top() << endl;

    // To confirm answer
    cout << "Manual evaluation result: " << ((7 + 9) * 4 / 8 - 3) << endl;

    return 0;
}
