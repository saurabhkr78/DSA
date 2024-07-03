// https://leetcode.com/problems/longest-subsequence-with-limited-sum

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());

        // Calculate prefix sums
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1];
        }

        // Answer each query
        vector<int> ans(m, 0); // answer vector with size m
        for (int i = 0; i < m; ++i) {
            int length = 0;
            // Binary search lagao ji
            int low = 0;
            int hi = n - 1;
            while (low <= hi) {
                int mid = low + (hi - low) / 2;
                if (nums[mid] > queries[i]) {
                    hi = mid - 1;
                } else {
                    length = mid + 1;
                    low = mid + 1;
                }
            }
            ans[i] = length;
        }
        return ans;
    }
};
