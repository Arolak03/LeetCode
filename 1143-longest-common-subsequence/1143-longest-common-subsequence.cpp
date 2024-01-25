class Solution {
public:
    
    
    int solve(string& x, string& y, int i, int j, vector<vector<int>>& dp){
        if(i>=x.length() || j>=y.length())return 0;
        //include
        if(dp[i][j]!=-1)return dp[i][j];
        if(x[i]==y[j])return dp[i][j]=1+solve(x,y,i+1,j+1,dp);
        return dp[i][j]=max(solve(x,y,i+1,j,dp),solve(x,y,i,j+1,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        //longest
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1,-1));
        return solve(text1, text2, 0, 0,dp);
    }
};