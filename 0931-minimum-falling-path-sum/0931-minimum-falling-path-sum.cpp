class Solution {
public:
    
    // vector<vector<int>> dp(101, vector<int>(101,-1));
    int dp[101][101];
    int solve(vector<vector<int>> &mat, int row, int col){
        if(row>=mat.size())return 0;
        // int left=0;
        if(dp[row][col]!=-1000)return dp[row][col];
        int mid=mat[row][col]+solve(mat,row+1,col);
        if(col-1>=0)
            mid=min(mid,mat[row][col-1]+solve(mat,row+1,col-1));
        // int right=0;
        if(col+1!=mat[0].size())
            mid=min(mid,mat[row][col+1]+solve(mat,row+1,col+1));
        // int mid=mat[row][col]+solve(mat,row+1,col);
        return dp[row][col]=mid;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int sum=INT_MAX;
        // int row=0;

        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j]=-1000;
            }
        }
        // vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1,-1));
        for(int i=0;i<matrix.size();i++){
            
            sum=min(sum,solve(matrix,0,i));
        }
        return sum;
    }
};