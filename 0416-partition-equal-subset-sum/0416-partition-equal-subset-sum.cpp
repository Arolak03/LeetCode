class Solution {
public:
    bool targetsum(vector<int>& nums, int index, int target,vector<vector<int>>& dp){
        int n = nums.size();
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(index>=n){
            return 0;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        // int sum = 0 ;
        // if(sum<=target){
        //     int incl= nums[index]+target(nums,index+1,target-nums[index]);
        // }
        // int exc = 0+target(nums,index+1,target);
        bool incl = targetsum(nums,index+1,target-nums[index],dp);
        bool excl = 0+targetsum(nums,index+1,target-0,dp);    
        return dp[index][target] = incl or excl;
    
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
                for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return 0;
        }
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return targetsum(nums,0,target,dp);
        
        
    }
};