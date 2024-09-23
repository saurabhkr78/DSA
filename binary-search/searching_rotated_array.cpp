#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int start, int end, int ele) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Check if the mid element is the target
            if (arr[mid] == ele) {
                return mid;
            }

            // Check the previous element
            if (mid > start && arr[mid - 1] == ele) {
                return mid - 1;
            }

            // Check the next element
            if (mid < end && arr[mid + 1] == ele) {
                return mid + 1;
            }

            // Decide which half to continue searching
            if (arr[mid] >= arr[start]) { // Left half is sorted
                if (ele >= arr[start] && ele < arr[mid]) {
                    end = mid - 1; // Search in the left half
                } else {
                    start = mid + 1; // Search in the right half
                }
            } else { // Right half is sorted
                if (ele > arr[mid] && ele <= arr[end]) {
                    start = mid + 1; // Search in the right half
                } else {
                    end = mid - 1; // Search in the left half
                }
            }
        }
        return -1; // Element not found
    }

    // Function to initiate search
    int searchElement(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Example of a rotated array
    int target = 0;
    
    int result = sol.searchElement(nums, target);
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
