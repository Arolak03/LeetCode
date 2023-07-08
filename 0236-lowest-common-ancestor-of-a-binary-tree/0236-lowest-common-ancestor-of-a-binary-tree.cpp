/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        //left m gyi and right m gyi of root
        TreeNode* leftAns = lowestCommonAncestor(root -> left, p ,q);
        TreeNode* rightAns = lowestCommonAncestor(root -> right, p ,q);
        // agr null returned ya not null returned
        if(leftAns == NULL && rightAns!=NULL){
            return rightAns;
        }
        if(leftAns != NULL && rightAns==NULL){
            return leftAns;
        }
        if(leftAns != NULL && rightAns!=NULL){
            return root;
        }
        else{
            return NULL;
        }
        
    }
};