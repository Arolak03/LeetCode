class Solution {
public:
    int solve(vector<int> &prices, int ind, int n,int fee, int buy, vector<vector<int>>& dp){
        int profit = 0;
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        //if we buy
        if(buy==0){
            profit=max(0+solve(prices,ind+1,n,fee,0,dp),-prices[ind]+solve(prices,ind+1,n,fee,1,dp));
        }
        //we sell
        if(buy==1){
            profit=max(0+solve(prices,ind+1,n,fee,1,dp),prices[ind]-fee+solve(prices,ind+1,n,fee,0,dp));
        }
        return dp[ind][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n =prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return solve(prices,0,n,fee,0,dp);
    }
};