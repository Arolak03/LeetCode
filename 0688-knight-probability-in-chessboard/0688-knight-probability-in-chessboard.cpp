class Solution {
public:
    double solve(int n, int k, int row, int col, vector<vector<vector<double>>>& dp){
        if(k==0){
            if (k == 0) {
            return (row >= 0 && row < n && col >= 0 && col < n) ? 1.0 : 0.0;
            }
        }
        if(dp[row][col][k]!=-1){
            return dp[row][col][k];
        }
       double count = 0.0;
        int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        
        for (int i = 0; i < 8; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                count += solve(n, k - 1, newRow, newCol,dp);
            }
        }

        // int ans = pow(8,k);
        return dp[row][col][k]=count/8;
        
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n,vector<double>(k+1,-1)));
        
        return solve(n,k,row,column,dp);
    }
};