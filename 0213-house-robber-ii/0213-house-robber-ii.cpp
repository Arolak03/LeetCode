class Solution {
public:
    int solve1(vector<int>& nums, int index, vector<int>& dp) {
        // Base case: If the index is out of bounds, return 0
        // cout<<index<<endl<<dp[0];
        if (index >= nums.size()-1) {
            // cout<<'*';
            return 0;
          
        }
        if (dp[index] != -1) {
            // cout<<'#';
            return dp[index];
        }
        int exclude=0;
        int include = nums[index] + solve1(nums, index + 2, dp);
        exclude = solve1(nums, index + 1, dp);
        return dp[index] = max(include, exclude);
    }

    int solve(vector<int>& nums, int index, vector<int>& dp) {
        // Base case: If the index is out of bounds, return 0
        if (index >= nums.size()) return 0;
        if (dp[index] != -1) return dp[index];
        int exclude=0;
        int include = nums[index] + solve(nums, index + 2, dp);
        // int exclude = solve(nums, index + 1, dp);
         exclude = solve(nums, index + 1, dp);
        return dp[index] = max(include, exclude);
    }

    int rob(vector<int>& nums) {
        int ans=INT_MIN;
        if(nums.size()<=3){
            for(int i=0;i<nums.size();i++){
                ans=max(ans,nums[i]);
            }
            return ans;
                        
        }
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);   
        int a = solve1(nums, 0, dp1);
        int b = solve(nums, 1, dp2);
        cout<<a<<b;
        return max(a, b);
    }
};
