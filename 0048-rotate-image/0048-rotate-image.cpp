class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =matrix.size();
        vector<vector<int>> mat=matrix;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=matrix[n-j-1][i];
            }
        }
        matrix=mat;
    }
};