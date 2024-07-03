// https://leetcode.com/problems/running-sum-of-1d-array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> sum(n);
        sum[0]=nums[0];
        for(int i=1;i<n;i++){
            sum[i]=nums[i]+sum[i-1];
        }
        return sum;
    }
};