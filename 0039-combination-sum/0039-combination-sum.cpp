class Solution {
public:
    
    void solve(vector<int>& nums, int& target,int index, int sum, vector<vector<int>>& ans, vector<int>& op){
        if(index==nums.size()){
          
            return;
        }
        if(sum>=target){
              if(sum==target){
                ans.push_back(op);
            }
            return;
        }
        
        op.push_back(nums[index]);
        sum+=nums[index];
        solve(nums,target,index,sum,ans,op);
        
        op.pop_back();
        sum-=nums[index];
        solve(nums,target,index+1,sum,ans,op);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(candidates, target, 0,0, ans, op);
        return ans;
    }
};