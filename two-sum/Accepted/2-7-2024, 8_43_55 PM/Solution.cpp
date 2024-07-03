// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if (map.count(comp)) {
                return {map[comp], i};
            }
            map[nums[i]] = i;
        }
        return {}; // if complement not found
    }
};
