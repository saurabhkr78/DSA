#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void pushAtBottom(stack<int>& st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }

    int topElement = st.top();
    st.pop();
    pushAtBottom(st, x);
    st.push(topElement);
}

// Function to reverse the stack recursively
void reverseStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }

    int topElement = st.top();
    st.pop();
    reverseStack(st);
    pushAtBottom(st, topElement);
}

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    // Reverse the stack
    reverseStack(st);

    // Print stack elements from top to bottom
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
