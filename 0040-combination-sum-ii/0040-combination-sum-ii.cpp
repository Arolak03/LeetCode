class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& op, int index) {
        if (target == 0) {
            ans.push_back(op);
            return;
        }
        if (index >= candidates.size() || target < 0)
            return;

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates
            } 
            if (candidates[i]>target) {
                break; // Skip duplicates
            } 

            op.push_back(candidates[i]);
            solve(candidates, target - candidates[i], ans, op, i + 1);
            op.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;

        sort(candidates.begin(), candidates.end()); // Sort the candidates
        solve(candidates, target, ans, op, 0);

        // set<vector<int>> uniqueCombinations(ans.begin(), ans.end());
        // ans.assign(uniqueCombinations.begin(), uniqueCombinations.end());

        return ans;
    }
};
