class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr && targetSum == 0) return false;
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) return true;
        
        bool leftSum = hasPathSum(root->left, targetSum - root->val);
        bool rightSum = hasPathSum(root->right, targetSum - root->val);

        return leftSum || rightSum;
    }
};
