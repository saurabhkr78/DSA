#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    vector<int> v;
    
    // Function to calculate Maximum Area Histogram (MAH)
    auto MAH = [](vector<int> &v) {
        vector<int> right;
        vector<int> left;
        stack<pair<int, int>> s;

        // Step 1: Calculate 'right' array (nearest smaller element to the right)
        for (int j = v.size() - 1; j >= 0; j--) {
            while (!s.empty() && s.top().first > v[j]) {
                s.pop();
            }
            if (s.empty()) {
                right.push_back(v.size());
            } else {
                right.push_back(s.top().second);
            }
            s.push({v[j], j});
        }
        reverse(right.begin(), right.end());

        // Clear stack for reuse
        while (!s.empty()) {
            s.pop();
        }

        // Step 2: Calculate 'left' array (nearest smaller element to the left)
        for (int j = 0; j < v.size(); j++) {
            while (!s.empty() && s.top().first >= v[j]) {
                s.pop();
            }
            if (s.empty()) {
                left.push_back(-1);
            } else {
                left.push_back(s.top().second);
            }
            s.push({v[j], j});
        }

        // Step 3: Calculate width and area arrays
        vector<int> width(v.size());
        vector<int> area(v.size());

        for (int i = 0; i < v.size(); i++) {
            width[i] = right[i] - left[i] - 1;
            area[i] = v[i] * width[i];
        }

        // Step 4: Find the maximum area
        int maxArea = 0;
        for (int i = 0; i < v.size(); i++) {
            maxArea = max(maxArea, area[i]);
        }

        return maxArea;
    };

    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Initialize the histogram with the first row of the matrix
    for (int j = 0; j < cols; j++) {
        v.push_back(matrix[0][j] - '0');
    }

    // Calculate the maximum area for the first row
    int maxArea = MAH(v);
    
    // Traverse through the remaining rows of the matrix
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '0') {
                v[j] = 0;
            } else {
                v[j] += (matrix[i][j] - '0');
            }
        }
        maxArea = max(maxArea, MAH(v));
    }

    cout << "Maximum area of rectangle in the binary matrix is: " << maxArea << endl;

    return 0;
}
