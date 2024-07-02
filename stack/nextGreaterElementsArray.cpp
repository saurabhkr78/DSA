#include <iostream>
#include <stack>
#include <vector> // Included for using vector
using namespace std;

stack<int> st;

int main() {
    int arr[] = {4, 1, 2, 5, 4, 3, 4, 8, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Initialize the answer array with zeros
    vector<int> ans(size, 0);
    
    // Push the first element onto the stack to avoid empty stack issues
    st.push(arr[0]);
    
    for (int i = 1; i < size; i++) {
        if (!st.empty() && st.top() >= arr[i]) {
            
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.pop();
            st.push(arr[i]);
        } 
        
        else {
            st.push(arr[i]);
        }
    }
    
    // Print the ans array
    for (int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
