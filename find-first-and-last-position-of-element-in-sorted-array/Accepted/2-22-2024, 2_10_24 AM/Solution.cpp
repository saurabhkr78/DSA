// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int left = 0, right = nums.size() - 1;

        // Find the left index of the range
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }

        if (nums.size() == 0 || nums[left] != target) return result;
        else result[0] = left;

        // Find the right index of the range
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }

        result[1] = left - 1;
        return result;
    }
};
