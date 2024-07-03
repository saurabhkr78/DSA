// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) 
            return false;
            /*The mapping is set to i + 1 (not just i) because the initial value in the mapping arrays is 0, and we need to distinguish between a character that hasn’t been seen yet and a character that was first seen at index 0.*/
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
