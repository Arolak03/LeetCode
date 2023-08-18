class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& op, int index, vector<int>& nums, int target) {
        if (target == 0) {
            ans.push_back(op);
            return;
        }
        
        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates to avoid duplicate combinations
            }
            
            if (nums[i] > target) {
                break; // Since candidates are sorted, remaining candidates are even larger
            }
            
            op.push_back(nums[i]);
            solve(ans, op, i + 1, nums, target - nums[i]); // Pass i + 1 to avoid repeating subsets
            op.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> temp;
        sort(candidates.begin(), candidates.end());
        vector<int> op;
        solve(temp, op, 0, candidates, target);
        
        return temp;
    }
};
