// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> a(150, 50);
        for (int i = 0; i < s.size(); i++) {
            int ascii = (int)s[i];
            if (a[ascii] == 50)
                a[ascii] = s[i] - t[i];
            else if (a[ascii] != s[i] - t[i])
                return false;
        }
        // again empty the vector
        for (int i = 0; i < 150; i++) 
            a[i] = 50;

            for (int i = 0; i < t.size(); i++) {
                int ascii = (int)t[i];
                if (a[ascii] == 50)
                    a[ascii] = t[i] - s[i];
                else if (a[ascii] != t[i] - s[i])
                    return false;
            }
        return true;
    }
    
};