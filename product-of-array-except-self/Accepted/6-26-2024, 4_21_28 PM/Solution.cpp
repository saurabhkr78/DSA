// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);
        int product = 1;
        for (int i = 0; i < n; i++) {
            output[i] *= product;
            product *= nums[i];
        }

        product = 1; // Reset product
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= product; 
            product *= nums[i]; 
        }

        return output;
    }
};
