#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    stack<int> temp;
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    // Transfer elements from st to temp
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    // Print elements from temp (bottom to top of original stack)
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;

    return 0;
}
