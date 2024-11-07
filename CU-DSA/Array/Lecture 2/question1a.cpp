#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binary_search(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            return mid;

        // modify binary search
        // if(arr[left] == target) return left;
        // if(arr[right] == target) return right;

        if(arr[mid] > target){
            right = mid - 1;
        } else left = mid + 1;
    }
    return -1;
}

int main() {
    int arr[] = {-1, 0, 3, 5, 9, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Linear Search
    int position = linear_search(arr, size, 9);

    if (position != -1) {
        cout << "9 is in array at position: " << position << endl;
    } else {
        cout << "9 is not available in array" << endl;
    }

    // Binary Search

    position = binary_search(arr, size, 9);

    if (position != -1) {
        cout << "9 is in array at position: " << position << endl;
    } else {
        cout << "9 is not available in array" << endl;
    }

    
    return 0;
}
