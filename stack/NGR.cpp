/*
Approach:
Initialize a Stack:

We use a stack to keep track of elements in the array. The idea is to store potential "next greater" elements in this stack as we traverse the array from right to left.
Traverse the Array from Right to Left:

We iterate from the last element to the first, because for each element we need to find the next greater element on its right side.
The stack helps us efficiently find the greater elements by removing unnecessary comparisons.
Logic:

For each element:
If the stack is empty, there is no element to the right, so push -1 into the result vector.
If the top element of the stack is greater than the current element, push the stack's top element into the result vector.
If the stack’s top element is less than or equal to the current element, keep popping from the stack until you find a greater element or the stack becomes empty.
After processing the element, push the current element onto the stack because it could be the next greater element for future elements.
Reverse the Result:

Since we traverse the array from right to left, the next greater elements are added in reverse order, so we need to reverse the result at the end.

*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> v; // To store the result
    stack<int> s;   // Stack to keep track of greater elements

    // Traverse from right to left
    for(int i = n - 1; i >= 0; i--) {
        if(s.empty()) {
            v.push_back(-1);  // No greater element to the right
        } 
        else if(s.top() > arr[i]) {
            v.push_back(s.top());  // Top element is greater
        } 
        else {
            // Pop elements from the stack that are smaller than or equal to arr[i]
            while(!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            // Check if stack is empty
            if(s.empty()) {
                v.push_back(-1);  // No greater element to the right
            } else {
                v.push_back(s.top());  // Next greater element found
            }
        }
        s.push(arr[i]);  // Push current element onto the stack
    }

    // Reverse the result since we traversed from the right
    reverse(v.begin(), v.end());

    // Print the result
    cout << "Next Greater Elements: ";
    for(auto it : v) {
        cout << it << " ";
    }
    
    return 0;
}
