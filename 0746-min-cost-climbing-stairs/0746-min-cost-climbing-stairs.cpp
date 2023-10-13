class Solution {
public:
    
    
//     int mincost(vector<int>& cost, int n, vector<int>& dp){
        
//         if(n==0){
//             return cost[0];
//         }
//         if(n==1){
//             return cost[1];
//         }
//         if (dp[n]!=-1){
//             return dp[n];
//         }
//         dp[n] = cost[n]+min(mincost(cost,n-1,dp),mincost(cost,n-2,dp));
//         return dp[n];
        
        
//     }
//     int mincost2(vector<int>& cost, int n){
//         vector<int>dp(n+1);
//         dp[0]=cost[0];
//         dp[1]=cost[1];
//         for(int i=2;i<n;i++){
//             dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
//         }
//         return min(dp[n-1],dp[n-2]);
        
        
//     }
//      int mincost3(vector<int>& cost, int n){
//         // vector<int>dp(n+1);
//         int prev2=cost[0];
//         int prev1=cost[1];
//         int curr;
//         for(int i=2;i<n;i++){
//             curr=cost[i]+min(prev1,prev2);
//             prev2=prev1;
//             prev1=curr;
//         }
//         return min(prev1,prev2);
        
        
//     }
    
    int solve(vector<int>& arr, int index,vector<int>& dp){
        if(index>=arr.size()){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        //normal
        int mini1 = min(arr[index]+solve(arr,index+1,dp),arr[index]+solve(arr,index+2,dp));
        return dp[index]=mini1;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        // vector<int>dp (n+1,-1);
        // int ans=min(mincost2(cost,n-1,dp),mincost2(cost,n-2,dp));
        // return ans;
        vector<int> dp1(cost.size()+1,-1);
        vector<int> dp2(cost.size()+1,-1);
        int ans1=solve(cost,1,dp1);
        int ans2=solve(cost,0,dp2);
        return min(ans1,ans2);
    }
};