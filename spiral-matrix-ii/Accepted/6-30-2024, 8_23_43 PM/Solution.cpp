// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int>(n)); 
        int minr = 0;
        int maxr = n - 1;
        int minc = 0;
        int maxc = n - 1;
        int count = 1;

        while (minr <= maxr && minc <= maxc) {
            // Traverse from left to right
            for (int j = minc; j <= maxc; j++) {
                arr[minr][j] = count++;
            }
            minr++;

            // Traverse from top to bottom
            for (int i = minr; i <= maxr; i++) {
                arr[i][maxc] = count++;
            }
            maxc--;

            // Traverse from right to left
            if (minr <= maxr) {
                for (int j = maxc; j >= minc; j--) {
                    arr[maxr][j] = count++;
                }
                maxr--;
            }

            // Traverse from bottom to top
            if (minc <= maxc) {
                for (int i = maxr; i >= minr; i--) {
                    arr[i][minc] = count++;
                }
                minc++;
            }
        }

        return arr;
    }
};
