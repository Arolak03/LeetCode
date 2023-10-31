class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& op, vector<vector<int>>& ans, int index) {
        if (target == 0) {
            ans.push_back(op);
            return;
        }
        if (target < 0 || index >= candidates.size()) {
            return;
        }
        
        // Include the current candidate and make a recursive call
        op.push_back(candidates[index]);
        solve(candidates, target - candidates[index], op, ans, index);
        op.pop_back();
        
        // Skip the current candidate and make a recursive call
        solve(candidates, target, op, ans, index + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> op;
        vector<vector<int>> ans;
        solve(candidates, target, op, ans, 0);
        return ans;
    }
};
