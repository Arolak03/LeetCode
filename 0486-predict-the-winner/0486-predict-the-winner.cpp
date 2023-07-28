class Solution {
public:
    
    int solve(vector<int>& nums, int l, int r, int n,vector<vector<int>>& dp){
        if(l==r){
            return nums[l];
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int scorer = nums[r]-solve(nums,l,r-1,n,dp);
        int scorel=nums[l]-solve(nums,l+1,r,n,dp);
        return dp[l][r]=max(scorer,scorel);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
          int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
      
        
        return solve(nums,0,n-1,n,dp) >=0;
        
    }
};