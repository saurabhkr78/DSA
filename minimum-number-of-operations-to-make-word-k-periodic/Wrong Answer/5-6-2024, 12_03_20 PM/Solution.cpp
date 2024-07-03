// https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.length();
        int operations = INT_MAX;

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

        return operations;
    }
};
