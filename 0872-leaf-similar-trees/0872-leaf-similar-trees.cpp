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
    
    void leaf(TreeNode* root, vector<int>& ans){
        if(!root->left && !root->right){
            ans.push_back(root->val);
            return;
        }
        if(root==NULL)return;
        if(root->left)leaf(root->left,ans);
        if(root->right)leaf(root->right,ans);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> ans2;
        leaf(root1,ans);
        leaf(root2,ans2);
        if(ans==ans2)return true;
        return false;
    }
};