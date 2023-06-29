class Solution {
public:
    int stock(vector<int>& arr, int  index, bool buy, vector<vector<int>>& dp){
        int n = arr.size();
        if(index==n){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit =0;
        if(buy){//can be bought
            profit = max(-arr[index]+stock(arr, index+1,0,dp),0+stock(arr,index+1,1,dp)); //still can be bought
        }
        else{
            profit = max(arr[index]+stock(arr,index+1,1,dp),0+stock(arr,index+1,0,dp));
        }
        return dp[index][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp (n+1,vector<int>(2,-1));
        
        return stock(prices,0,1,dp);
    }
};