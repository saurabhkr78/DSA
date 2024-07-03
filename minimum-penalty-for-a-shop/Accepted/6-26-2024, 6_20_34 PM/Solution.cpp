// https://leetcode.com/problems/minimum-penalty-for-a-shop

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> pre(n + 1); // no of N before kth hr
        vector<int> suf(n + 1); // no of Y after and including Kth hr

        // prefix sum of 'N's
        pre[0] = 0;
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (customers[i] == 'N' ? 1 : 0);
        }

        //  suffix sum of 'Y's
        suf[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }

        int minPenalty = n;
        for (int i = 0; i <= n; i++) {
            int pen = pre[i] + suf[i];
            minPenalty = min(minPenalty, pen);
        }

        for (int i = 0; i <= n; i++) {
            int pen = pre[i] + suf[i];
            if (pen == minPenalty) {
                return i;
            }
        }

        return n; // Default case (closing at nth hour)
    }
};
