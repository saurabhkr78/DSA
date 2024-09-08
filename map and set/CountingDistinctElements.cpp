#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> distinctElementsInWindow(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        vector<int> result;

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            m[arr[i]]++;
        }
        result.push_back(m.size()); // Number of distinct elements in the first window

        // Slide the window
        for (int i = k; i < arr.size(); i++) {
            // Remove the element that is sliding out of the window
            m[arr[i - k]]--;
            if (m[arr[i - k]] == 0)
                m.erase(arr[i - k]);

            // Add the new element that is sliding into the window
            m[arr[i]]++;

            // Record the number of distinct elements in the current window
            result.push_back(m.size());
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;

    vector<int> result = sol.distinctElementsInWindow(arr, k);

    cout << "Distinct elements in each window of size " << k << ": ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
