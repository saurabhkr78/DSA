#include <iostream>
#include <vector>


using namespace std;

// Function to check if the array can be partitioned into two subsets with equal sum
int totalSum=0;
bool canPartition(vector<int> &nums)
{
    for(int i:nums){
        totalSum+=i;
    }

    // If the total sum is odd, we can't partition it into two equal subsets
    if (totalSum % 2 != 0)
    {
        return false;
    }

    int target = totalSum / 2;
    int n = nums.size();

    // Create a DP table of size (n+1) x (target+1) and initialize it to false
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Initialize dp[i][0] to true, because we can always form sum 0 with any number of elements (by choosing none)
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= target; ++j)
        {
            if (j >= nums[i - 1])
            {
                // Either we include nums[i-1] or we don't
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
            else
            {
                // We can't include nums[i-1] because it's larger than the current sum j
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The result will be in dp[n][target], which tells us if we can form sum "target" using all n numbers
    return dp[n][target];
}

// Main function
int main()
{
    // Example 1
    vector<int> nums1 = {1, 5, 11, 5};
    if (canPartition(nums1))
    {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    }
    else
    {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }

    // Example 2
    vector<int> nums2 = {1, 2, 3, 5};
    if (canPartition(nums2))
    {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    }
    else
    {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }

    return 0;
}
