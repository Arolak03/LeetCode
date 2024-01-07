class Solution {
public:
    #define MOD 1000000007;
    
    int solve(int start, int end, int k, int index,vector<vector<int>>& dp){
        if(k==0 && index==end)return 1;
        if(k<0)return 0;
        if(dp[index+999][k]!=-1)return dp[index+999][k];
        int right=solve(start,end,k-1,index+1,dp)%MOD;
        int left=solve(start,end,k-1,index-1,dp)%MOD;
        return dp[index+999][k]=(left + right)%MOD;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3000, vector<int>(k+1,-1));
        return solve(startPos,endPos,k,startPos,dp)%MOD;
    }
};
 // int mod = 1e9 + 7;
 //    long long solve(int curr, int endPos, int k, vector<vector<int>>& dp){
 //        if(k == 0){
 //            return curr==endPos;
 //        }
 //        if(dp[999+curr][k] != -1){
 //            return dp[999+curr][k];
 //        }
 //        l
 //    }