// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zero_count = 0;
        for(int i=0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                product *= nums[i];
            }
            else
            {
                zero_count++;
            }
            
        }

        for(int i=0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                if(zero_count)
                {
                    nums[i] = 0;
                }
                else
                {
                    nums[i] = product/nums[i];
                }
            }
            else
            {
                if(zero_count > 1)
                {
                    nums[i] = 0;
                }
                else
                {
                    nums[i] = product;

                }
                
            }
        }

        return nums;
    }
};
