// https://leetcode.com/problems/minimum-length-of-anagram-concatenation

#include <unordered_set>

class Solution {
public:
    int minAnagramLength(string s) {
        unordered_set<char> unique_chars(s.begin(), s.end());
        return unique_chars.size();
    }
};
