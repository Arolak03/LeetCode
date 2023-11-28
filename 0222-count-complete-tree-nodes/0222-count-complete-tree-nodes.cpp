#include <cmath>

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftHeight = 0, rightHeight = 0;
        TreeNode *left = root, *right = root;

        while (left) {
            left = left->left;
            leftHeight++;
        }

        while (right) {
            right = right->right;
            rightHeight++;
        }

        if (leftHeight == rightHeight) {
            // If left and right subtrees have the same height, the tree is complete
            return (1 << leftHeight) - 1; // 2^leftHeight - 1
        } else {
            // If the heights are different, recursively count nodes in left and right subtrees
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
