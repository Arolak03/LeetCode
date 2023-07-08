class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans, int& count, int k) {
        if (root == nullptr) {
            return;
        }
        ans.push_back(root->val);
        solve(root->left, ans, count, k);
        solve(root->right, ans, count, k);
        long long sum = 0;  // Change type to long long
        int size = ans.size();
        for (int i = size - 1; i >= 0; i--) {
            sum += ans[i];
            if (sum == k) {
                count++;
            }
        }
        ans.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        int count = 0;
        solve(root, ans, count, targetSum);
        return count;
    }
};
