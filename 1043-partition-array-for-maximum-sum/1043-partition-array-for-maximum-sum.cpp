class Solution {
public:
    int solve(vector<int>& arr, int start, int k, vector<int>& dp){
        if(start>=arr.size())return 0;
        if(dp[start]!=-1)return dp[start];
        int n =arr.size();
        int end=min(n,start+k);
        int ans=0;
        int currMax=0;
        for(int i=start;i<end;i++){
            currMax=max(currMax,arr[i]);
            ans=max(ans, currMax*(i-start+1)+solve(arr,i+1,k,dp));
        }
        return dp[start]=ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,-1);
        return solve(arr,0,k,dp);
    }
};