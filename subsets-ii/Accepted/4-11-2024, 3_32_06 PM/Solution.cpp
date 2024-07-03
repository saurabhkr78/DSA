// https://leetcode.com/problems/subsets-ii

void storeSub(vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>& result) {
    result.push_back(subset);
    for (int i = idx; i < nums.size(); i++) {
        if (i > idx && nums[i] == nums[i - 1]) {
            continue;
        }
        subset.push_back(nums[i]);
        storeSub(nums, i + 1, subset, result);
        subset.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        storeSub(nums, 0, subset, result);
        return result;
    }
};