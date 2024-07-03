// https://leetcode.com/problems/valid-word

class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) {
            return false;
        }
        string valid_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        for (char c : word) {
            if (valid_chars.find(c) == string::npos) {
                return false;
            }
        }
        string vowels = "aeiouAEIOU";
        if (word.find_first_of(vowels) == string::npos) {
            return false;
        }
        string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
        if (word.find_first_of(consonants) == string::npos) {
            return false;
        }
        return true;
    }
};
