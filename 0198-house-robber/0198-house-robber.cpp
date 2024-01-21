class Solution {
public:
    
    int solve(vector<int>& nums, int index, vector<int>& dp){
        if(index>=nums.size())return 0;
        //ye ya fr next
        if(dp[index]!=-1)return dp[index];
        int first=nums[index]+solve(nums,index+2,dp);
        int second=solve(nums,index+1,dp);
        return dp[index]=max(first,second);
    }
    
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};