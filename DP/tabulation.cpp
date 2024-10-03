/*
tabulation approach aka bottom up approach
This is called a bottom-up approach because it starts by solving the smallest subproblems and uses their results to solve larger subproblems.
-no recursion
-only table
1.[size][bagcapacity]==[i][j]
*/



#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int BagCapacity, int size)
{
    // Create a 2D dp table with (size+1) rows and (BagCapacity+1) columns
    vector<vector<int>> dp(size + 1, vector<int>(BagCapacity + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= size; i++)
    {
        for (int w = 1; w <= BagCapacity; w++)
        {
            // If the current item's weight is less than or equal to the remaining capacity
            if (wt[i - 1] <= w)
            {
                // Include the item and check if it's better to include or exclude
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                // If the item is too heavy, exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The bottom-right corner of the matrix contains the maximum value
    return dp[size][BagCapacity];
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int BagCapacity = 7;
    int size = sizeof(wt) / sizeof(wt[0]);

    cout << "Maximum value in knapsack: " << knapsack(wt, val, BagCapacity, size);
    return 0;
}
