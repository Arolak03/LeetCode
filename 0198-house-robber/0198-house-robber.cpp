class Solution {
public:
    int money(vector<int>& nums, int index, vector<int>& dp){
        int n = nums.size();
        if(index>=n){
            return 0;
        }
        
        if(dp[index]!=-1){
            return dp[index];
        }
        int incl = nums[index]+money(nums,index+2,dp);
        int excl = 0+money(nums,index+1,dp);
        dp[index]= max(incl,excl);
        return dp[index];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return money(nums,0, dp);
    }
};