// https://leetcode.com/problems/minimum-length-of-anagram-concatenation

#include <vector>

class Solution {
public:
    int minAnagramLength(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        int max_count = *max_element(count.begin(), count.end());
        return s.length() / max_count;
    }
};
