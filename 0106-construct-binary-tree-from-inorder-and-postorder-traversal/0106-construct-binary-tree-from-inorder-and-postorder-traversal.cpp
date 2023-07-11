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
    
    void mapping(vector<int>& in, map<int, int> &mp,int n){
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
            }
    }
    TreeNode* solve(vector<int>& post, vector<int>& in, int& index, int inStart, int inEnd, int n,map<int, int>& mp){
        if(index<0 || inStart>inEnd){
            return NULL;
        }
        // lement kaunsajiski index chahiye
        int elem = post[index--];
        TreeNode* root = new TreeNode(elem);
        //uski position
        int pos = mp[elem];
        
        // ab right call and left call
        root->right = solve(post,in,index,pos+1,inEnd, n,mp);
        root->left = solve(post, in, index, inStart, pos-1,n,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= postorder.size();
        map<int, int> mp;
        mapping(inorder,mp,n);
        int postOrderIndex = n-1;
        TreeNode* ans=solve(postorder,inorder,postOrderIndex,0,n-1,n,mp);
        return ans;
    }
};