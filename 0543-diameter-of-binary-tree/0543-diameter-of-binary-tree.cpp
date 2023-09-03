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
    
    int solve(TreeNode* root, int& diam){
        if(root==NULL){
            return 0;
        }
        int lh = solve(root->left,diam);
        int rh = solve(root->right,diam);
        diam = max(diam,lh+rh);
        return 1+max(lh,rh);
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diam =0 ;
        solve(root, diam);
        return diam;
    }
};