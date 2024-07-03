// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);

        // Calculate prefix array
        int product = nums[0];
        pre[0] = 1;
        for (int i = 1; i < n; i++) {
            pre[i] = product;
            product *= nums[i];
        }

        // Calculate suffix array
        // Reset product
        product = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            pre[i] *= product;
            product *= nums[i];
        }
        return pre;
    }
};
