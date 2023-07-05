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
    
    pair<int, int> solve(TreeNode* root){
        if(root == NULL){
            pair<bool, int>p = make_pair(true,0);
            return p;
        }
        pair<int, int> left = solve(root ->left);
        pair<int, int> right = solve(root ->right);
        
        //first rue false
        //second height
        bool leftt = left.first;
        bool rightt=right.first;
         bool diff = abs(left.second - right.second) <=1;
        pair<bool, int> ans;
        ans.second = max(left.second , right.second)+1;
       
        if(leftt && rightt && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    
    
    bool isBalanced(TreeNode* root) {
        // //left - right <= 1
        // if(root==NULL){
        //     return true;
        // }
        // bool left = isBalanced(root -> left);
        // bool right = isBalanced(root -> right);
        // bool condn = abs(height(root->left)-height(root->right))<=1;
        // if(left && right && condn){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        return solve(root).first;
        
        
    }
};