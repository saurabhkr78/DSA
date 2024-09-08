#include <vector>
#include <algorithm> // For std::max
#include <climits>   // For LLONG_MIN
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return -1; // Check if k is larger than the size of the array
        
        long long sum = 0;
        long long max_sum = LLONG_MIN;
        int i = 0, j = 0;
        
        // Expand the window until its size is k
        while (j < n) {
            sum += nums[j];
            
            // If the window size is less than k, continue expanding
            if (j - i + 1 < k) {
                j++;
            }
            // If the window size is exactly k
            else if (j - i + 1 == k) {
                max_sum = max(max_sum, sum); // Update max_sum with the current window sum
                sum -= nums[i]; // Remove the element that is sliding out of the window
                i++; // Slide the window by moving the start index forward
                j++; // Continue expanding the window
            }
        }
        
        return max_sum;
    }
};
