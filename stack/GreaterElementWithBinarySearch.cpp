#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> st;

// Binary search to find the next greater element in arr[]
int binarySearch(int arr[], int left, int right, int target) {
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (st.top() >= arr[mid]) {
            result = mid;
            left = mid + 1;  // Search on the right side for a greater element
        } else {
            right = mid - 1; // Search on the left side
        }
    }

    return result;
}

int main() {
    int arr[] = {4, 1, 2, 5, 4, 3, 4, 8, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans; // Initialize ans with -1 indicating no next greater element found

    st.push(arr[0]);

    for (int i = 1; i < size; i++) {
        // While stack is not empty and top of stack is smaller than arr[i]
        while (!st.empty() && st.top() < arr[i]) {
            int index = binarySearch(arr, i, size - 1, st.top()); // Binary search in arr[] for the next greater element
            if (index != -1) {
                ans = arr[i];
            }
            st.pop(); // Pop the element from stack
        }
        st.push(arr[i]); // Push arr[i] to stack
    }

    // Print the ans array
    cout <<ans<<endl;

    return 0;
}
