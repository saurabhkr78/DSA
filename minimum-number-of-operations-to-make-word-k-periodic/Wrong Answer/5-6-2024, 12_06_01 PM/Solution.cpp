// https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.length();
        int operations = INT_MAX;
        
        // If k = 1, just need to find the most frequent character and count the rest
        if (k == 1) {
            int freq[26] = {0}; // Assuming only lowercase English alphabets
            for (char c : word) {
                freq[c - 'a']++;
            }
            int maxFreq = *max_element(freq, freq + 26);
            operations = n - maxFreq; // Operations needed = Total characters - Most frequent character count
        } else {
            // Iterate over all possible starting indices for k-periodic substrings
            for (int start = 0; start < k; ++start) {
                // Initialize the count for current starting index
                int count = 0;
                for (int i = start; i < n; i += k) {
                    // If the character at index i is different from the character at the starting index,
                    // increment the count
                    if (word[i] != word[start]) {
                        count++;
                    }
                }
                // Update the minimum operations required
                operations = min(operations, count);
            }
        }

        return operations;
    }
};