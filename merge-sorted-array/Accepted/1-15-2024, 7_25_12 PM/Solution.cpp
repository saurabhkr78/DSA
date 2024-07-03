// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i = 0;
        int j = 0;
        vector<int> v;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                v.push_back(nums1[i]);
                i++;
            } else {
                v.push_back(nums2[j]);
                j++;
            }
        }

        while (j < m) {
            v.push_back(nums2[j]);
            j++;
        }

        while (i < n) {
            v.push_back(nums1[i]);
            i++;
        }

        nums1 = v; // Assign the merged vector to nums1 directly
    }
};
