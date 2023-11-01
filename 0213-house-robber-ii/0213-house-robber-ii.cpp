class Solution {
public:
     int solve1(vector<int>& nums, int index, vector<int>& dp){
         //last nhi aayega
        if(index>=nums.size()-1)return 0;
        if(dp[index]!=-1)return dp[index];
        int include=nums[index]+solve(nums,index+2,dp);
        int exclud=solve(nums,index+1,dp);
        return dp[index]=max(include, exclud);
    
    }
     int solve(vector<int>& nums, int index, vector<int>& dp){
        if(index>=nums.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int include=nums[index]+solve(nums,index+2,dp);
        int exclud=solve(nums,index+1,dp);
        return dp[index]=max(include, exclud);
    
    }
    int rob(vector<int>& nums) {
        vector<int> nums1;
        if(nums.size()==1)return nums[0]; 
        for(int i=0;i<nums.size()-1;i++){
            nums1.push_back(nums[i]);
        }
        vector<int> nums2;
        
        for(int i=1;i<nums.size();i++){
            nums2.push_back(nums[i]);
        }
            
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        int a=solve(nums1,0,dp1);
        int b=solve(nums2,0,dp2);
        // cout<<a<<endl<<b;
        return max(a,b);
    }
};