class Solution {
public:
    int solve(vector<vector<int>> arr, int row, int col, vector<vector<int>>& dp){
        int m = arr.size();
        int n = arr[0].size();
        if(arr[m-1][n-1]==1){
            return 0;
        }
        if(row==m-1 && col==n-1){
            return 1;
        }
        if(row>=m || col>=n || arr[row][col]==1 ){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int ways=0;
        // if(row>=0 && row<m && col>=0 && col<n){
            // if(arr[row][col]!=1){
                //right ans bottom
                ways = solve(arr,row+1,col,dp)+solve(arr,row,col+1,dp);
            // }
            
        // }
        return dp[row][col]=ways;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return solve(obstacleGrid,0,0,dp);
    }
};