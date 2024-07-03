// https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic



class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> freqMap;
        for (int i = 0; i < word.size(); i += k) {
            freqMap[word.substr(i, k)]++;
        }
        int maxFreq = 0;
        for (auto entry : freqMap) {
            maxFreq = max(maxFreq, entry.second);
        }
        return (word.size() / k) - maxFreq;
    }
};
