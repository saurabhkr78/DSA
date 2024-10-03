// DP with tabulation
/*
Problem Statement:
Given a set of n integers and a target sum S, determine if there is a subset of the given set whose sum is exactly S.
Example:
Set: {3, 34, 4, 12, 5, 2}
Target Sum: 9
Answer: Yes (Because the subset {4, 5} adds up to 9).

*/
#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int set[], int size, int sum)
{
    // Create a 2D array to store results of subproblems
    bool dp[size + 1][sum + 1];

    // Initialize the dp array
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                dp[i][j] = false; // No subset with 0 items can achieve any positive sum
            }
            if (j == 0)
            {
                dp[i][j] = true; // Sum of 0 can always be achieved by selecting no items
            }
        }
    }

    // Fill the subset table in bottom-up manner
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (set[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j]; // If current element is greater than the sum, exclude it
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]]; // Check both including and excluding the current element
            }
        }
    }

    // Return the bottom-right value in the table (whether subset with the sum exists)
    return dp[size][sum];
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int size = sizeof(set) / sizeof(set[0]);

    if (isSubsetSum(set, size, sum))
        cout << "Yes, a subset exists with the given sum." << endl;
    else
        cout << "No, subset does not exist with the given sum." << endl;

    return 0;
}
