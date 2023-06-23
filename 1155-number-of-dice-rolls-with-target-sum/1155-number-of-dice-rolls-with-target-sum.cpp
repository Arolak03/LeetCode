class Solution {
public:
    int mod = 1e9+7;
    long long dice(int n, int k, int target, vector<vector<long long>>& dp){
        if(target<0){
            return 0;
        }
        if(n==0 && target!=0){
            return 0;
        }
        if(n!=0 && target ==0){
            return 0;
        }
        if(target==0 && n==0){
            return 1;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        //2D as target and n
        
        long long ans = 0;   
        for(int i=1;i<=k;i++){
            ans = (ans + dice(n-1,k,target-i,dp))%mod;
            
        }
        return dp[n][target] = ans;
    }
    
    long long numRollsToTarget(int n, int k, int target) {
        
        vector<vector<long long>> dp(n+1,vector<long long>(target+1,-1));
        return dice(n,k,target,dp);
    }
};