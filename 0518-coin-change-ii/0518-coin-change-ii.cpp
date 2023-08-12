class Solution {
public:

    int solve(int amount, vector<int>& coins, int index, vector<vector<int>>& dp){
        int n =coins.size();

        if(amount==0){
            return 1;
        }
        if(index>=n){
            return 0;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        //include
        int ways;         
        if(coins[index]>amount){
            return ways = solve(amount,coins,index+1,dp);
        }
        //1 way
        ways = solve(amount-coins[index],coins,index,dp)+solve(amount,coins,index+1,dp);
        return dp[index][amount]=ways;
        
    }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }
};