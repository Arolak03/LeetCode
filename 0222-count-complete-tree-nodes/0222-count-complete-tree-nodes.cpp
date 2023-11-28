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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q  ;
        vector<TreeNode*>ans;
        if(!root)return NULL;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp);
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        return ans.size();
    }
};