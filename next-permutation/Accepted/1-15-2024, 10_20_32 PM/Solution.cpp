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
        // if array is greatest
        if (idx == -1) {

            reverse(nums.begin(), nums.end());
            return;
        }
        // 2.sorting/reverse after pivot
        reverse(nums.begin() + idx + 1, nums.end());

        // 3.finding just greatest index than pivot
        int j = -1;
        for (int i = idx + 1; i < n; i++) {
            if (nums[i] > nums[idx]) {
                j = i;
                break;
            }
        }
        // 4.swapping idx and j
        int temp = nums[idx];
        nums[idx] = nums[j];
        nums[j] = temp;
        return;
    }
};