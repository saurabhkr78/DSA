#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Base case: sum of 0 can always be achieved with an empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                // We can either include arr[i-1] or exclude it
                 dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                // Cannot include arr[i-1], so carry forward the value
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Return whether we can achieve the sum with all elements
    return dp[n][sum];
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (isSubsetSum(arr, sum)) {
        cout << "Subset with given sum exists." << endl;
    } else {
        cout << "Subset with given sum does not exist." << endl;
    }

    return 0;
}
