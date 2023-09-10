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
    void mapping(map<int, int>& mpp, vector<int>& inorder){
        //index wala map bna diya
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
    }
    
TreeNode* solve(vector<int>& in, vector<int>& post, int inStart, int inEnd, int& index,int n, map<int, int>& mpp) {
    if (index < 0 || inStart > inEnd) return NULL;

    int elem = post[index--];
    int pos = mpp[elem];
    TreeNode* root = new TreeNode(elem);
    root->right = solve(in, post, pos + 1, inEnd, index,n, mpp);
    root->left = solve(in, post, inStart, pos - 1, index,n, mpp);
    return root;
}
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int ,int> mpp;
        mapping(mpp, inorder);
        int n = inorder.size();
        int index=0;
        int postOrderIndex=n-1;
        return solve(inorder, postorder,0, n-1,postOrderIndex, n, mpp);
    }
};