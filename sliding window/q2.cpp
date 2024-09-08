//first -ve in every window size of k

#include <bits/stdc++.h>
using namespace std;

vector<int> printFirstNegativeInteger(int arr[], int n, int k) {
    int i = 0, j = 0;
    deque<int> finalres;
    vector<int> res;

    while (j < n) {
        // Add the current negative number to the deque
        if (arr[j] < 0) {
            finalres.push_back(arr[j]);
        }
        
        // If the window size is less than k, expand the window
        if (j - i + 1 < k) {
            j++;
        }
        // If the window size is k
        else if (j - i + 1 == k) {
            // If there are no negative numbers in the current window
            if (finalres.empty()) {
                res.push_back(0);
            } else {
                // Add the first negative number of the current window
                res.push_back(finalres.front());
                // Remove the number if it's going out of the window
                if (arr[i] < 0) {
                    finalres.pop_front();
                }
            }
            // Slide the window
            i++;
            j++;
        }
    }
    return res;
}

int main() {
    int arr[] = {12, -1, -2, 8, -16, 30, 16, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    vector<int> result = printFirstNegativeInteger(arr, n, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
