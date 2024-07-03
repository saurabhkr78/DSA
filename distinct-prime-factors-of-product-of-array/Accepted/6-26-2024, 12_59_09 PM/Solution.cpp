// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array

class Solution {
public:
    void fillarray(vector<bool> &array) {
        int size = array.size() - 1;
        for (int i = 2; i <= sqrt(size); i++) {
            if (array[i]) {
                for (int j = i * i; j <= size; j += i) {
                    array[j] = false;
                }
            }
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {
        if (nums.empty()) return 0;

         int n=nums.size();
        int mx=-1;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
        }
        vector<bool> array(mx + 1, true);
        if(mx+1>0) array[0]=0;
        if(mx+1>1) array[1]=0;
        fillarray(array);

        vector<int> prime;
        for (int i = 2; i <= mx; i++) {
            if (array[i]) prime.push_back(i);
        }

        vector<bool> exist(prime.size(), false);
        for (int i = 0; i < nums.size(); i++) {
            int ele = nums[i];
            for (int j = 0; j < prime.size(); j++) {
                if (prime[j] > ele) break;
                if (ele % prime[j] == 0) exist[j] = true;
            }
        }

        int count = 0;
        for (int i = 0; i < exist.size(); i++) {
            if (exist[i]) count++;
        }

        return count;
    }
};
