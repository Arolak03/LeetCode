class Solution {
public:
    
    // int solve(int k, vector<int>& arr, int index, int buy, vector<vector<vector<int>>>& dp){
    //     int n =arr.size();
    //     if(k==0 || index>=n){
    //         return 0;
    //     }
    //     if(dp[index][buy][k]!=-1){
    //         return dp[index][buy][k];
    //     }
    //     int profit = 0;
    //     if(buy){
            // profit = max(-arr[index]+solve(k,arr,index+1,0,dp), 0+solve(k,arr, index+1,1,dp));
    //     }
    //     else{
            // profit = max(arr[index]+solve(k-1,arr,index+1,1,dp),0+solve(k,arr,index+1,0,dp));
    //     }
    //     return dp[index][buy][k]=profit;
    // }
    int solve(int k , vector<int>& arr, int index, int count, vector<vector<int>>& dp){
        int n = arr.size();
        
        if(index>=n || count==2*k){
            return 0;
        }
        int profit = 0;
        if(dp[index][count]!=-1){
            return dp[index][count];
        }
        if(count % 2 ==0){
            // buy
             profit = max(-arr[index]+solve(k,arr,index+1,count+1,dp), 0+solve(k,arr, index+1,count,dp));
        }
        else{
            // not buy
             profit = max(arr[index]+solve(k,arr,index+1,count+1,dp),0+solve(k,arr,index+1,count,dp));
        }
        return dp[index][count]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n =prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        // return solve(k,prices,0,1,dp);
        vector<vector<int>> dp(n, vector<int>(2*k,-1));
        return solve(k,prices,0,0,dp);
    }
};