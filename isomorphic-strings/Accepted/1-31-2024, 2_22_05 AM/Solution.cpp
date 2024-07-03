// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //default case
        if (s.size() != t.size())
            return false;
    /*150 total numbers of characters and with their value i cann't aet it's value to 0 because diff of two char can be 0*/
        vector<int> a(150, 50);
        //from S's pov 
        for (int i = 0; i < s.size(); i++) {

            int ascii = (int)s[i];//for index
     /*to check that index by comparing with default value if yes then do ⬇️*/
            if (a[ascii] == 50)
                a[ascii] = s[i] - t[i];//two char subtraction gives a number
             //check this too   
            else if (a[ascii] != s[i] - t[i])
                return false;
        }
        // again empty the vector
        for (int i = 0; i < 150; i++) 
            a[i] = 50;
        // T's pov
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