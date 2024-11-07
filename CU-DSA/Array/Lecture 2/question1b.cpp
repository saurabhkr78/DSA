#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int rotational_binary_search(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            return mid;

        if(arr[left] <= arr[mid]){
            if(arr[left] <= target && target < arr[mid])
                right = mid - 1;
            else left = mid + 1;
        } else{
            if(arr[mid] < target && target <= arr[right])
                left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Linear Search
    int position = linear_search(arr, size, 0);

    if (position != -1) {
        cout << "0 is in array at position: " << position << endl;
    } else {
        cout << "0 is not available in array" << endl;
    }

    // Binary Search

    position = rotational_binary_search(arr, size, 0);

    if (position != -1) {
        cout << "0 is in array at position: " << position << endl;
    } else {
        cout << "0 is not available in array" << endl;
    }

    
    return 0;
}
