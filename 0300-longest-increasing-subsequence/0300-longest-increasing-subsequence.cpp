#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
        int bottomUp(vector<int>& nums){
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));

        for(int curr=nums.size()-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){

                 
                    int include=0;
                    if(prev==-1||nums[curr]>nums[prev])
                        include=1+dp[curr+1][curr+1];
                    
                    //exclude
                    int exclude=dp[curr+1][prev+1];
                    dp[curr][prev+1]= max(include,exclude);
                    
                }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
         int prev=-1,curr=0;
        return bottomUp(nums);
    }
};
