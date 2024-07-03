// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>suf(n);
        vector<int>ans(n);
        //for prefix array
        int product=nums[0];
        pre[0]=1;
        for(int i=1;i<n;i++){
            pre[i]=product;
            product*=nums[i];
        }
        //for suffix array
        // reset product
        product=nums[n-1];
        suf[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suf[i]=product;
            product*=nums[i];
        }
        //ans  into prefix array
        for(int i=0;i<n;i++){
            pre[i]=pre[i]*suf[i];
        }
        return pre;

    }
};
