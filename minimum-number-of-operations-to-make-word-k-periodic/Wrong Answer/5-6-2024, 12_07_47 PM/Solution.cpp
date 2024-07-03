// https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.length();
        int operations = INT_MAX;

        // Count the occurrences of each character
        vector<int> freq(26, 0); // Assuming only lowercase English alphabets
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Iterate over all possible characters
        for (char c = 'a'; c <= 'z'; ++c) {
            // If the character doesn't occur in the word, skip
            if (freq[c - 'a'] == 0) continue;

            // Calculate the number of operations to make the entire word k-periodic with character c
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if ((i % k != 0 && word[i] == c) || (i % k == 0 && word[i] != c)) {
                    count++;
                }
            }

            // Update the minimum operations required
            operations = min(operations, count);
        }

        return operations == INT_MAX ? -1 : operations;
    }
};
