// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1.finding pivot
        int n = nums.size();
        int pi = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pi = i;
                break;
            }
        }
        // if array is greatest
        if (pi == -1) {

            reverse(nums.begin(), nums.end());
            return;
        }
        // 2.sorting/reverse after pivot
        reverse(nums.begin() + pi + 1, nums.end());

        // 3.finding just greatest index than pivot
        int j = -1;
        for (int i = pi + 1; i < n; i++) {
            if (nums[i] > nums[pi]) {
                j = i;
                break;
            }
        }
        // 4.swapping idx and j
        int temp = nums[pi];
        nums[pi] = nums[j];
        nums[j] = temp;
        return;
    }
};