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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> op;
        // if(root==NULL){
        //     return NULL;
        // }
        queue<TreeNode*> q;
        // stack<vector<int>> s;
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
            op.push_back(ans);
            // s.push(ans);
        }
        
        // op.push_back(stack);
        // reverse(op.begin(), op.end());
        // return op;
        vector<double> avg;
        for(int i=0;i<op.size();i++){
            double sum=0;
            for(int j=0;j<op[i].size();j++){
                sum+=op[i][j];
            }
            sum/=op[i].size();
            avg.push_back(sum);
        }
            
        return avg;
    }
};
