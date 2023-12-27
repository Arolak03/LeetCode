class Solution {
public:
    #define mod 1000000007;
    long long solve(int n, int k, int target, vector<vector<long long>>& dp){
        if(target==0 && n==0)return 1;
        if(target!=0 && n==0)return 0;
        if(target==0 && n!=0)return 0;
        if(target<0 || n<0)return 0;
        if(dp[n][target]!=-1)return dp[n][target];
        long long ans=0;
        for(int i=1;i<=k;i++)ans =(ans+solve(n-1,k,target-i,dp))%mod;
        return dp[n][target]=ans%mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1, vector<long long>(target+1,-1));
        long long ans=solve(n,k,target,dp);
        return ans%mod;
    }
};