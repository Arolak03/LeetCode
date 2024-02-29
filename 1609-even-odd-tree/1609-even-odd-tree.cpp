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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        // vector<TreeNode*> ans;
        if(root->val%2==0)return false;
        bool even=false;
        while(!q.empty()){
            int sz=q.size();
            vector<TreeNode*> ans;
            while(sz--){
                
                TreeNode* top=q.front();
                q.pop();
                // ans.push_back(top->val);
                if(top->left){
                    q.push(top->left);
                    ans.push_back(top->left);
                    // if(even){
                    //     if(top->left->val%2==0)return false;
                    // }
                    // else{
                    //     if(top->left->val%2!=0)return false;
                    // }
                }
                if(top->right){
                    q.push(top->right);
                    ans.push_back(top->right);
                    // if(even)if(top->right->val%2==0)return false;
                    // else if(top->right->val%2!=0)return false;
                }
                // even=!even;
            }
            int prev=-1;
            for(int i=0;i<ans.size();i++){
                if(even){
                    if(ans[i]->val%2==0 || prev>=ans[i]->val)return false;
                }
                else{
                    if(ans[i]->val%2!=0 || (i>0 && prev<=ans[i]->val)){
                        cout<<ans[i]->val<<prev;
                        return false;
                    }
                }
                prev=ans[i]->val;
            }
            even=!even;
        }
        return true;
        
    }
};