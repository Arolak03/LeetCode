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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> op;
        if(root==NULL){
            return op;
        }
        queue<TreeNode*> q;
        stack<vector<int>> s;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> ans;
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    
                }
                if(temp->right){
                    q.push(temp->right);
                }
                ans.push_back(temp->val);
            }
            
            s.push(ans);
        }
        while(!s.empty()){
            op.push_back(s.top());
            s.pop();
        }
        // reverse(op.begin(), op.end());
        return op;
        
    }
};