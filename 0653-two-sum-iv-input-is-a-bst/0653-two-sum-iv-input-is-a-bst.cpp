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
    
    void solve(TreeNode* root, vector<int>& ans){
        if(root==NULL)return;
        
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        solve(root,ans);
        // int ind = ans.size();
        // for(int i=0;i<ind-1;i++){
        //     for(int j=i+1;j<ind;j++){
        //         if(ans[i]+ans[j]==k ){
        //             return true;
        //         }
        //     }
        // }
        int s =0;
        int e=ans.size()-1;
        while(s<e){
        int sum=ans[e]+ans[s];
            if(sum==k){
                return true;
            }
            if(sum>k){
                e=e-1;
            }
            else{
                s=s+1;
            }
        }
        return false;
    }
};