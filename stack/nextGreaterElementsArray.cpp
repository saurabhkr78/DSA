#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int arr[] = {3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans(size, -1); // Initialize ans with -1 indicating no next greater element found

    stack<int> st; // Stack to keep track of indices

    for (int i = 0; i < size; i++) {
        // While stack is not empty and the current element is greater than the element at the index stored in st.top()
        while (!st.empty() && arr[st.top()] < arr[i]) {
            ans[st.top()] = arr[i]; // Update ans for the index where we found the next greater element
            st.pop(); // Pop the element from stack
        }
        st.push(i); // Push the current index onto the stack
    }

    // Print the ans array
    for (int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
