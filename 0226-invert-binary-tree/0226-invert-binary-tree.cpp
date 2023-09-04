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
//     void merge(TreeNode* root,TreeNode* left, TreeNode* right){
//         TreeNode* temp = root->right;
//         root->left=root->right;
//         root->right=temp;
//         delete(temp);
//     }
    
//     void solve(TreeNode* root){
//         if(root-> left->left == NULL || root-> right-> right==NULL)return;
//         // solve(root->left);
//         // solve(root->right);
//         TreeNode* left  = root->left;
//         TreeNode* right = root->right;
        // TreeNode* temp = root->left;
        // root->left=root->right;
        // root->right=root->left;
//         delete(temp);
//     }
    
    TreeNode* invertTree(TreeNode* root) {
        
//         solve(root);
//         merge(root,root->left, root->right) ;
//         return root;
        
        if(root==nullptr)return nullptr;
        TreeNode* temp = root->left;
        root->left=root->right;
        root->right=temp;
       
       
        invertTree(root->right);
         invertTree(root->left);
        return root;
        
    }
};