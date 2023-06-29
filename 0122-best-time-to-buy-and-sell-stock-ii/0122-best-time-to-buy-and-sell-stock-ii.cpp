class Solution {
public:
    int stock(vector<int>& arr){
        // int n = arr.size();
        // if(index==n){
        //     return 0;
        // }
        // if(dp[index][buy]!=-1){
        //     return dp[index][buy];
        // }
        // int profit =0;
        // if(buy){//can be bought
        //     profit = max(-arr[index]+stock(arr, index+1,0,dp),0+stock(arr,index+1,1,dp)); //still can be bought
        // }
        // else{
        //     profit = max(arr[index]+stock(arr,index+1,1,dp),0+stock(arr,index+1,0,dp));
        // }
        // return dp[index][buy] = profit;
        int n = arr.size();
        vector<vector<int>>dp (n+1, vector<int>(2,0));
        for(int index= n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                
                 int profit =0;
                 if(buy){//can be bought
                    profit = max(-arr[index]+dp[index+1][0],0+dp[index+1][1]); //still can be bought
                  }
                 else{
                    profit = max(arr[index]+dp[index+1][1],dp[index+1][0]);
                  }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
        
    }
    
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>>dp (n+1,vector<int>(2,-1));
        
        return stock(prices);
    }
};