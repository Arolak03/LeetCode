class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& op, vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(op);
            return;
        }
        op.push_back(nums[index]);
        solve(nums,index+1,op,ans);
        op.pop_back();
        solve(nums,index+1,op,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        vector<vector<int>> ans;
        solve(nums,0,op,ans);
        return ans;
    }
};