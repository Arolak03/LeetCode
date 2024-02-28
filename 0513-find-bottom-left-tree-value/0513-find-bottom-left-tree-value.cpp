class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int result = 0;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (i == 0) {
                    result = node->val;  // Update result with the leftmost node in each level
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return result;
    }
};
