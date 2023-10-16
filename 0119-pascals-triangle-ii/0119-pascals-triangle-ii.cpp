class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> mat(rowIndex+1, vector<int>(rowIndex+1,1));
        // // first and last
        // for(int i=0;i<=rowIndex;i++){
        //     mat[i][0]=1;
        //     mat[i][i]=1;
        // }
        for(int i=2;i<=rowIndex;i++){
            for(int j=1;j<i;j++){
                mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
            }
        }
        return mat[rowIndex];
        
    }
};