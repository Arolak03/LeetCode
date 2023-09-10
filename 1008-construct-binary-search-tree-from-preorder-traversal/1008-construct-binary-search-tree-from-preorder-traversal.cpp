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
    // TreeNode* solve(vector<int>& preorder){
    //     if(preorder.size()==0)return NULL;
    //     TreeNode* root= new TreeNode(preorder[0]);
    //     // if(preorder.size()==1)return root;
    //     vector<int> left, right;
    //     for(int i=0;i<preorder.size();i++){
    //         if(preorder[i]>preorder[0]){
    //             right.push_back(preorder[i]);
    //         }
    //         else if(preorder[i]<preorder[0]){
    //             left.push_back(preorder[i]);
    //         }
    //     }
    TreeNode* solve(vector<int>& preorder, int& i, int bound){
        if(i==preorder.size() || preorder[i]>bound){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        
    
    
        root->left=solve(preorder,i, root->val);
        root->right=solve(preorder,i, bound);
        return root;
    
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder, i, INT_MAX);
    }
};