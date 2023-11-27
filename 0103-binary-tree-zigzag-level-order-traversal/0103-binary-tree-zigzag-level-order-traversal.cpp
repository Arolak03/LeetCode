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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        // int index=0;
        queue<TreeNode*> q;
        bool left=true;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            // if(left){
            //     for(int i=0;i<sz;i++){
            //         ans[index][i]=q.front()
            //     }
            // }
            vector<int> op(sz);
            for (int i = 0; i < sz; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                int index = left ? i : (sz - 1 - i);
                op[index] = temp->val;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        left=!left;
        ans.push_back(op);
        }
        return ans;
    }
};