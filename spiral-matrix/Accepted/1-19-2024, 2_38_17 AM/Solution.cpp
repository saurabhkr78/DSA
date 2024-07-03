// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // to find row in 2D array
        int m = matrix.size();
        // to find col in 2D array
        int n = matrix[0].size();
        int minr = 0;
        int minc = 0;
        int maxr = m - 1;
        int maxc = n - 1;
        int ttn = n * m;
        int count = 0;
        vector<int> v;

        while (minr <= maxr && minc <= maxc) {
            // right printing row where row is fixed and col is being printed
            for (int j = minc; j <= maxc && count < ttn; j++) {
                v.push_back(matrix[minr][j]);
                count++;
            }
            minr++;

            // down printing where col is fixed and row is being printed
            for (int i = minr; i <= maxr && count < ttn; i++) {
                v.push_back(matrix[i][maxc]);
                count++;
            }
            maxc--;

            // left printing where row is fixed and column is being printed
            for (int j = maxc; j >= minc && count < ttn; j--) {
                v.push_back(matrix[maxr][j]);
                count++;
            }
            maxr--;

            // up printing where col is fixed and row is being printed
            for (int i = maxr; i >= minr && count < ttn; i--) {
                v.push_back(matrix[i][minc]);
                count++;
            }
            minc++;
        }
        return v;
    }
};
