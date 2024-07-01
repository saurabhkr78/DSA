#include <iostream>
#include <stack>
using namespace std;

// Function to push an element at the bottom of the stack
void pushAtBottom(stack<int>& st, int x) {
    // Base case
    if (st.empty()) {
        st.push(x);
        return;
    }

    //remove the top element and hold it
    int topElement = st.top();
    st.pop();
    pushAtBottom(st, x);

    // Put the held element back on top
    st.push(topElement);
}

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    int newElement = 5;
    pushAtBottom(st, newElement);

    // Print stack elements from top to bottom
    stack<int> temp;
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
