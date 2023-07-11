/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parentMap;
    void dfs(TreeNode*root, TreeNode* parent){
        if(root==NULL){
            return;
        }
        parentMap[root]=parent;
        dfs(root->left,root);
        dfs(root->right,root);
        return;
    }
    unordered_map<TreeNode*, bool> vis;
    vector<int> solve(TreeNode* root, int k){
        if(root==NULL || vis[root]){
            return vector<int>();
        }
        if(k==0){
            return vector<int>(1,root->val);
        }
        vis[root]=true;
        vector<int> op1=solve(root->left,k-1);
        vector<int> op2=solve(root->right,k-1);
        vector<int> op3=solve(parentMap[root],k-1);
        
        op1.insert(op1.end(),op2.begin(),op2.end());
        op1.insert(op1.end(),op3.begin(),op3.end());
        return op1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root,NULL);
        return solve(target,k);
    }
};