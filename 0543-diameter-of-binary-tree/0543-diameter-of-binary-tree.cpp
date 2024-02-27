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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(height(root->left), height(root->right))+1;
    }
    
    int solve(TreeNode* root, int& maxi){
        if(root==NULL)return 0;
        int left = height(root->left);
        int right = height(root->right);
        maxi=max(maxi, left+right);
        
        return max(solve(root->left,maxi), solve(root->right,maxi))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};