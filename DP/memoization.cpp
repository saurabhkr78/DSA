/*
memoization aka top down approach
This is called a top-down approach because the algorithm starts from the main problem and breaks it down into smaller subproblems as needed.


-recursion+with table
-only we create table of those varible whose value is being change in each recursive call
-in order to store last variable we create +1 size table

//memoization approach
1.initalization->base case
2.chnage recursive call to iterative version


*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int BagCapacity, int size, vector<vector<int>> &dp)
{
    // Base case: If no items left or capacity is 0, the result is 0
    if (size == 0 || BagCapacity == 0)
        return 0;

    // If the subproblem has already been solved, return the stored result
    if (dp[size][BagCapacity] != -1)
        return dp[size][BagCapacity];

    // If the weight of the current item is less than or equal to the remaining capacity
    if (wt[size - 1] <= BagCapacity)
    {
        // Store and return the result of the maximum between including or excluding the item
        dp[size][BagCapacity] = max(val[size - 1] + knapsack(wt, val, BagCapacity - wt[size - 1], size - 1, dp),
                                    knapsack(wt, val, BagCapacity, size - 1, dp));
    }
    else
    {
        // If the item is too heavy, skip it and store the result
        dp[size][BagCapacity] = knapsack(wt, val, BagCapacity, size - 1, dp);
    }

    return dp[size][BagCapacity];
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int BagCapacity = 7;
    int size = sizeof(wt) / sizeof(wt[0]);

    // Create a dp table with size+1 rows and BagCapacity+1 columns, initialized to -1
    vector<vector<int>> dp(size + 1, vector<int>(BagCapacity + 1, -1));

    cout << "Maximum value in knapsack: " << knapsack(wt, val, BagCapacity, size, dp);
    return 0;
}
// t.c: O(size×BagCapacity)
// s.c:O(size×BagCapacity)