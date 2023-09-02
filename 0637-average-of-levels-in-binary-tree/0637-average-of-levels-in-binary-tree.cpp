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
        vector<double> avg;
        if (root == nullptr) {
            return avg;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            double levelSum = 0.0;
            
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                levelSum += temp->val;
                
                if (temp->left) {
                    q.push(temp->left);
                }
                
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            
            avg.push_back(levelSum / size);
        }
        
        return avg;
    }
};
