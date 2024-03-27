class Solution {
public:
    
//     int solve(vector<int>& nums, int pro, int k, int index, vector<vector<int>>& dp){
//         if(index>=nums.size() || pro>=k)return 0;
//         if(dp[index][pro]!=-1)return dp[index][pro];
//         //include
//         // if(pro*nums[index]<k)int include=solve(nums,pro*nums[index],k,index+1);
//         // int exclude=solve(nums,pro,k,index+1);
//         // int include=0;
//         if(pro*nums[index]<k)return dp[index][pro]=1+solve(nums,pro*nums[index],k,index+1,dp);
//         // return include+exclude;
//         return dp[index][pro]=0;
        
//     }
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        // int count=0;
        // int n =nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
        // for(int i=0;i<n;i++){
        //     count+=solve(nums,1,k,i,dp);
        // }
        // return count;
        // // solve(nums,1,k,0);
        if(k==0)return 0;
        int count=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            long long pro=1;
            for(int j=i;j<n;j++){
                pro*=nums[j];
                if(k>pro){
                    count++;
                    // break;
                }
                if(k<=pro)break;
            }
        }
        return count;
        
        
        
    }
};