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
    TreeNode* lastRightFind(TreeNode* root){
        if(root->right==NULL)return root;
        return lastRightFind(root->right);
    }
    
    TreeNode* solve(TreeNode* root){
        // if (root==NULL) return NULL;
        //leaf  type ho
        if(!root->right)return root->left;
        else if(!root->left)return root->right;
        TreeNode* rightC=root->right;
        TreeNode* lastRight = lastRightFind(root->left);
        lastRight->right=rightC;
        return root->left;
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        //key dhoondo
        if(root==NULL)return NULL;
        if(root->val==key) return solve(root);
        TreeNode* dummy=root;
        while(root){
            if(root->val>key){
                //go left
                if(root->left && root->left->val==key){
                    root->left=solve(root->left);
                }
                else root=root->left;
            }
            else{
                //go left
                if(root->right && root->right->val==key){
                    root->right=solve(root->right);
                }
                else root=root->right;
            }
        }
        return dummy;
    }
};