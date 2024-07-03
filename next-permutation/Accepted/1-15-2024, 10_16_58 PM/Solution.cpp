// https://leetcode.com/problems/next-permutation



class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // 1. Finding pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // If array is greatest
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2. Sorting/reverse after pivot
        reverse(nums.begin() + idx + 1, nums.end());

        // 3. Finding just greater index than pivot and swapping
        for (int i = idx + 1; i < n; i++) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                return;
            }
        }
    }
};
