// class Solution {
// public:
//     bool solve(TreeNode* root, TreeNode* subRoot){
//         if (root == NULL && subRoot == NULL) return true;
//         if (root == NULL || subRoot == NULL) return false;

//         if (root->val != subRoot->val) {
//             return false;
//         }
//         return solve(root->left, subRoot->left) && solve(root->right, subRoot->right);
//     }
    
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if(subRoot==NULL || root==NULL)return false;
//         // if(root == NULL) return false;

//         if (solve(root, subRoot)){
//             return true;
//         }
//         return  solve(root->left, subRoot) || solve(root->right, subRoot) ;
//     }
// };
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot)
            return false;
        
        if (isSameTree(root, subRoot))
            return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }
};
