#include <iostream>
using namespace std;

int countSubsetSum(int arr[], int n, int sum) {
    int t[n + 1][sum + 1];

    // Initialize the table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }

    // Fill the table using bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}

int main() {
    int arr[] = {2, 3, 5, 6, 8,10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    cout << "No. of subsets = " << countSubsetSum(arr, size, sum);
    return 0;
}