#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> v;  // To store the result (next smaller elements)
    stack<int> s;   // Stack to keep track of smaller elements

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        if (s.empty()) {
            v.push_back(-1);  // No smaller element to the right
        } 
        else if (s.top() < arr[i]) {
            v.push_back(s.top());  // Top element is smaller
        } 
        else {
            // Pop elements from the stack that are greater than or equal to arr[i]
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            // Check if stack is empty
            if (s.empty()) {
                v.push_back(-1);  // No smaller element found
            } else {
                v.push_back(s.top());  // Next smaller element found
            }
        }
        s.push(arr[i]);  // Push current element onto the stack
    }

    // Reverse the result since we traversed from right to left
    reverse(v.begin(), v.end());

    // Print the result
    cout << "Next Smaller Elements: ";
    for (auto it : v) {
        cout << it << " ";
    }

    return 0;
}
