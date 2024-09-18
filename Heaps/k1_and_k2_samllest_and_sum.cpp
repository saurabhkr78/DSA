#include <bits/stdc++.h>
using namespace std;

int sumBetweenK1K2(int arr[], int n, int k1, int k2) {
    // Use a min-heap to find the k1-th and k2-th smallest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++) {
        minHeap.push(arr[i]);
    }

    // Extract the k1-th smallest element
    for (int i = 1; i < k1; i++) {
        minHeap.pop();
    }
    int k1_smallest = minHeap.top();

    // Extract the k2-th smallest element
    for (int i = k1; i < k2; i++) {
        minHeap.pop();
    }
    int k2_smallest = minHeap.top();

    // Now sum elements between k1-th and k2-th smallest
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > k1_smallest && arr[i] < k2_smallest) {
            sum += arr[i];
        }
    }

    return sum;
}

int main() {
    int arr[] = {1, 3, 12, 5, 15, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k1 = 3, k2 = 6; // Find the sum between 3rd smallest and 6th smallest
    int result = sumBetweenK1K2(arr, n, k1, k2);
    cout << "Sum of elements between " << k1 << "th and " << k2 << "th smallest elements is: " << result << endl;
    return 0;
}
