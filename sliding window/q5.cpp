/*Variable size window
--conditon matters here
--we vary our window according to conditoon
*/

/*

Q. Will the discussed approach work with negative numbers in the array?
A. No.
Because let's say in the given array [4,1,1,1,2,3,5] when we found the sum within the window to be greater than the desired value 5 (i=0, j=2 -> [4,1,1]), we started reducing the size of the window by doing i++. Here we assumed that once the sum of elements within the window becomes greater than 5 then increasing the window size will just add to the sum and hence we will not attain the sum 5 again. This is true when all the element are positive and hence reducing the window size by doing i++ makes sense. But this might not be true if array also contains negative numbers. Consider the array [4,1,1,-2,1,5], here we would have found the sum to be greater than 5 for i=0, j=2 and if we would have now started reducing the window size by doing i++, we would have missed the potential subarray (i=0, j=4).
In short, the discussed approach will not work with array having negative numbers.



*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; // `n` is the size of the array, and `k` is the target sum
    cin >> n >> k;
    vector<int> arr(n);

    // Input the array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i = 0, j = 0, sum = 0;
    int maxi = 0;

    // Sliding window algorithm
    while (j < n)
    {
        sum += arr[j]; // Add current element to the window

        // When the sum is less than the target, move the right pointer
        if (sum < k)
        {
            j++;
        }
        // If the sum is equal to the target, calculate the window size
        else if (sum == k)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
        // When the sum exceeds the target, shrink the window from the left
        else if (sum > k)
        {
            while (sum > k && i <= j)
            {
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }

    cout << maxi << endl; // Output the maximum length of the subarray with sum `k`

    return 0;
}
