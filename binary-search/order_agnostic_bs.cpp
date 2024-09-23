#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 4, 7, 19, 23, 56}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array
    int x = 7;  // Element to search
    int i = 0, j = n - 1;  // Search boundaries
    
    while(i <= j) {
        int mid = i + (j - i) / 2;  // Calculate middle index

        if(arr[mid] == x) { 
            cout << "Element found at index " << mid << endl;  // Return index if found
            return 0;
        }

        // Ascending order
        if(arr[0] < arr[n-1]) {
            if(x < arr[mid]) {
                j = mid - 1;  // Search in the left half
            } else {
                i = mid + 1;  // Search in the right half
            }
        }
        // Descending order
        else if(arr[0] > arr[n-1]) {
            if(x < arr[mid]) {
                i = mid + 1;  // Search in the right half for descending array
            } 
            else {
                j = mid - 1;  // Search in the left half for descending array
            }
        }
    }

    // If element is not found
    cout << "Element not found" << endl;
    return 0;
}
