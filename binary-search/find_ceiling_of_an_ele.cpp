#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findCeiling(vector<int> &arr, int x)
    {
        int i = 0, j = arr.size() - 1; // Use arr.size() to get the length
        int res = -1;

        while (i <= j)
        {
            int mid = i + (j - i) / 2;

            if (arr[mid] == x)
                return mid; // Element found

            if (arr[mid] > x)
            {
                res = mid ; // Update result to mid-1 index
                j = mid - 1;   // Search in the left half
            }
            else
                i = mid + 1; // Search in the left half
        }
        return res; // Return index of floor element, or -1 if not found
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;

    int result = sol.findCeiling(nums, target);

    if (result != -1)
    {
        cout << "Floor of " << target << " is: " << nums[result] << " at index: " << result << endl;
    }
    else
    {
        cout << "No floor found for " << target << endl;
    }

    return 0;
}
