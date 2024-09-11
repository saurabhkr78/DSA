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

    vector<int> v; // To store the result
    stack<int> s;  // Stack to keep track of smaller elements

    // Traverse the array from left to right
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            v.push_back(-1);  // No smaller element to the left
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

    // Print the result vector without reversing it
    cout << "Left Smaller Elements: ";
    for (auto it : v) {
        cout << it << " ";
    }

    return 0;
}
