#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& arr) {
    int n = arr.size();
    int i = 0, j = n - 1;

    while (i <= j) {
        int mid = i + (j - i) / 2; 

        // Check if mid is a peak element
        if (mid > 0 && mid < n - 1) {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return arr[mid];
            }
            else if (arr[mid - 1] > arr[mid]) {
                j = mid - 1; // Move left
            } else {
                i = mid + 1; // Move right
            }
        } else if (mid == 0) {
            return (arr[0] > arr[1]) ? arr[0] : arr[1]; // Compare with the next element
        } else if (mid == n - 1) {
            return (arr[n - 1] > arr[n - 2]) ? arr[n - 1] : arr[n - 2]; // Compare with the previous element
        }
    }
    
    return -1; 
}

int main() {
    vector<int> arr = {1, 3, 20, 4, 1, 0, 5}; // Example array
    int peak = findPeakElement(arr);

    cout << "Peak element is: " << peak << endl;

    return 0;
}
