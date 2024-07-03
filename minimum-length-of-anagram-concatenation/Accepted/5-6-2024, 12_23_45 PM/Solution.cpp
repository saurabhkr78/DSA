// https://leetcode.com/problems/minimum-length-of-anagram-concatenation

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();

        // Calculate the gcd of the lengths of all substrings of s
        int gcd_length = n;
        for (int size = 1; size < n; ++size) {
            if (n % size == 0) {
                bool is_anagram = true;
                for (int i = size; i < n; i += size) {
                    if (!isAnagram(s.substr(0, size), s.substr(i, size))) {
                        is_anagram = false;
                        break;
                    }
                }
                if (is_anagram) {
                    gcd_length = gcd(gcd_length, size);
                }
            }
        }

        return gcd_length;
    }

private:
    bool isAnagram(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};