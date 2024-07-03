// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1.finding pivot
        int n = nums.size();
        int idx = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) { // if array is greatest

            reverse(nums.begin(), nums.end());
            return;
        }
        // 2.sorting/reverse after pivot
        reverse(nums.begin() + idx + 1, nums.end());
        // 3.swapping idx and pivot
        int temp = nums[idx];
        nums[idx] = nums[idx + 1];
        nums[idx + 1] = temp;
        return;
    }
};