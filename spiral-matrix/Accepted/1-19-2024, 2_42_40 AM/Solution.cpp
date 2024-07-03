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
        
        vector<int> v;

        while (minr <= maxr && minc <= maxc) {
            if(minr>maxr || minc>maxc) break;
            // right printing row where row is fixed and col is being printed
            for (int j = minc; j <= maxc ; j++) {
                v.push_back(matrix[minr][j]);
               
            }
            minr++;
            if(minr>maxr || minc>maxc) break;
            // down printing where col is fixed and row is being printed
            for (int i = minr; i <= maxr; i++) {
                v.push_back(matrix[i][maxc]);
               
            }
            maxc--;
             if(minr>maxr || minc>maxc) break;
            // left printing where row is fixed and column is being printed
            for (int j = maxc; j >= minc ; j--) {
                v.push_back(matrix[maxr][j]);
                
            }
            maxr--;
            if(minr>maxr || minc>maxc) break;
            // up printing where col is fixed and row is being printed
            for (int i = maxr; i >= minr ; i--) {
                v.push_back(matrix[i][minc]);
            
            }
            minc++;
        }
        return v;
    }
};
