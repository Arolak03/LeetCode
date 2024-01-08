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
    
    class info{
        public:
        int maxi;
        int mini;
        int sum;
        bool isBST;
    };
    
    info solve(TreeNode* root, int& maxi){
        if(root==NULL){
            return {INT_MIN,INT_MAX,0,true};
        }
        info left=solve(root->left,maxi);
        info right=solve(root->right,maxi);
        info ans;
        ans.maxi=max(right.maxi,root->val);
        ans.mini=min(left.mini,root->val);
        ans.sum=root->val+left.sum+right.sum;
        if(root->val>left.maxi && root->val<right.mini && left.isBST && right.isBST){
            ans.isBST=true;
        }
        else ans.isBST=false;
        if(ans.isBST){
            maxi=max(maxi,ans.sum);
        }
        return ans;
    }
    
    int maxSumBST(TreeNode* root) {
        
        int maxi=0;
        solve(root,maxi);
        return maxi;
    }
};