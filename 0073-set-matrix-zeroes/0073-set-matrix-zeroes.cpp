class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<pair<int, int>> zeros; // To store the positions of zeros
        
        // Find the positions of zero elements
        for (int i = 0; i < m*n; ++i) {
            int row=i/n;
            int col =i%n;
        
                if (matrix[row][col] == 0) {
                    zeros.push_back(make_pair(row, col));
                }
            
        }
        
        // Set entire rows and columns to zero based on the stored positions
        for (const auto& zero : zeros) {
            int row = zero.first;
            int col = zero.second;
            
            for (int i = 0; i < m; ++i) {
                matrix[i][col] = 0; // Zero out the column
            }
            
            for (int j = 0; j < n; ++j) {
                matrix[row][j] = 0; // Zero out the row
            }
        }
    }
};
