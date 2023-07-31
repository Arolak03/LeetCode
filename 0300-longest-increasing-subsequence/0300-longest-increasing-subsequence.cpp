#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int solve(vector<int>& nums, int prev, int index, vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            return 0;
        }
        if(dp[prev+1][index]!=-1){
            return dp[prev+1][index];
        }
        
        // If we include the current element, we need to find the LIS from the next index
        int include = 0;
        if (prev ==-1 || nums[index] > nums[prev]) {
            include = 1 + solve(nums, index, index + 1,dp);
        }
        
        // If we exclude the current element, we need to find the LIS from the next index
        int exclude = solve(nums, prev, index + 1,dp);
        
        // Return the maximum LIS obtained from including or excluding the current element
        return dp[prev+1][index]=max(include, exclude);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // Start from the first element (index 0) and the previous index as -1
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1,-1));
        int prev=-1;
        int index=0;
        return solve(nums, prev, index,dp);
    }
};
