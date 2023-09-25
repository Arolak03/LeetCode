class Solution {
public:
    
    int solve(int n, vector<int>&dp){
        if(n<=1)return n;
        if(n==2)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans =0;
        ans+=solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
        return dp[n]=ans;
    
    }
    
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};