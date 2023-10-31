class Solution {
public:
    
    void solve(vector<int>& nums, int target, vector<int>& op, vector<vector<int>>& ans, int index){
        if(target==0){
            ans.push_back(op);
            return;
        }
        if(target<0 || index>=nums.size())return;
        op.push_back(nums[index]);
        solve(nums,target-nums[index],op,ans,index);
        op.pop_back();
        solve(nums, target, op, ans, index + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>op;
        vector<vector<int>> ans;
        solve(candidates,target,op,ans,0);
        return ans;
    }
};