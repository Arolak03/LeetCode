/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void solve(TreeNode* root, vector<int>& ans){
        if(root==NULL)return;
        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        solve(root,ans);
        int ind = ans.size();
        for(int i=0;i<ind-1;i++){
            for(int j=i+1;j<ind;j++){
                if(ans[i]+ans[j]==k ){
                    return true;
                }
            }
        }
        return false;
    }
};