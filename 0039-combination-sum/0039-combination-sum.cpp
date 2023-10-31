class Solution{
    public:
void solve(vector<int>& nums, int target, vector<int>& op, vector<vector<int>>& ans, int index) {
    if (target == 0) {
        ans.push_back(op);
        return;
    }
    if (target < 0 || index == nums.size()) {
        return;
    }
    
    for (int i = index; i < nums.size(); i++) {
        op.push_back(nums[i]);
        solve(nums, target - nums[i], op, ans, i); // Use i to move to the next element
        op.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> op;
    vector<vector<int>> ans;
    solve(candidates, target, op, ans, 0);
    return ans;
}
};
