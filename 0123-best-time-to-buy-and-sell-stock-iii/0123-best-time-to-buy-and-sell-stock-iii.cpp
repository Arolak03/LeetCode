class Solution {
public:
    
    int stocks(vector<int>& arr, int index, int buy, int count, vector<vector<vector<int>>>& dp){
        int n = arr.size();
        if(index>=n || count==0){
            return 0;
        }
        if(dp[index][buy][count] !=-1){
            return dp[index][buy][count];
        }
        int profit =0;
        
            if(buy){
                profit = max(-arr[index]+stocks(arr, index+1,0,count,dp),0+stocks(arr,index+1,1,count,dp));
            }
            else{
                profit = max(arr[index]+stocks(arr,index+1,1,count-1,dp), 0+stocks(arr, index+1,0,count,dp));
            }
        
        return dp[index][buy][count]=profit;
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp (n, vector<vector<int>>(2, vector<int>(3,-1)));
        return stocks(prices,0,1,2,dp);
                  
    }
};