class Solution {
public:
    int solve(int m, int n){
        // if(row==m-1 && col==n-1)return dp[row][col]=1;
        // if(col>=n || row>=m)return dp[row][col]=0;
        // if(dp[row][col]!=-1)return dp[row][col];
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        dp[m-1][n-1]=1;
        for(int i=0;i<m;i++){
            dp[i][n-1]=1;
        }
        for(int i=0;i<n;i++){
            dp[m-1][i]=1;
        }
        for(int row=m-2;row>=0;row--){
            for(int col=n-2;col>=0;col--){
                int right=dp[row][col+1];
                int down=dp[row+1][col];
                dp[row][col]=right+down;
            }
        }
        return dp[0][0];
        
        // return dp[row][col]=right+down;
    }
    int uniquePaths(int m, int n) {
        
        return solve( m, n);
    }
};