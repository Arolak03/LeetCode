#include <vector>
#include <queue>

using namespace std;



class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool leftRight = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size);
            for (int i = 0; i < size; i++) {
                TreeNode* frontNode = q.front();
                q.pop();
                int index = leftRight ? i : size - i - 1;
                ans[index] = frontNode->val;
                if (frontNode->left) {
                    q.push(frontNode->left);
                }
                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }
            leftRight = !leftRight;
            result.push_back(ans);
        }
        return result;
    }
};
