class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mat=matrix;
        for(int i=0;i<m*n;i++){
            int row = i/n;
            int col = i%n;
            if(matrix[row][col]==0){
                //row same rkhna h 
                for(int j=0;j<m;j++){
                    mat[j][col]=0;
                }
                //col same
                for(int j=0;j<n;j++){
                    mat[row][j]=0;
                }
            }
            // else{
            //     mat[row][col]=1;
            // }
        }
        matrix=mat;
    }
};
