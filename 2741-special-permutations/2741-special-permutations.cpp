class Solution {
public:
    #define MOD 1000000007
    int solve(vector<int>& nums, int count, int prev, vector<vector<int>>& dp, int mask){
        if(count>=nums.size())return 1;
        
        if(dp[prev][mask]!=-1)return dp[prev][mask];
        
        long long ways=0;
        for(int i=0;i<nums.size();i++){
            
            // if(vis[i])continue;
            if(mask & (1<<i))continue;
            //atleast one elment selected prev
            if(mask!=0 && nums[i]%nums[prev]!=0 && nums[prev]%nums[i]!=0){
                continue;
            }
            // vis[i]=true;
            ways=(ways+solve(nums,count+1,i,dp, mask|(1<<i))%MOD)%MOD;
        }
        return dp[prev][mask]=ways;
    }
    
    int specialPerm(vector<int>& nums) {
        int count=0;
        int prev=0;
        int n =nums.size();
        vector<vector<int>> dp(n, vector<int>((1<<n), -1));
        // vector<bool> vis (nums.size(), false);
        //initially no element selected
        int mask=0;
        return solve(nums,count,prev,dp,mask);
    }
};