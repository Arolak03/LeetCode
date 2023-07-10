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
//     int findPos(vector<int>& in,int&elem,int n){
//     {
//         for(int i=0;i<n;i++){
//             if(in[i]==elem)
//                 return i;
            
//         }
//         return -1;
//     }
     void mapping(vector<int> in,int n,map<int, int>& nodeToIndex){
    
        for(int i=0;i<n;i++){
            // if(in[i]==elem)
                nodeToIndex[in[i]]=i;
        }
        // return -1;
    }
TreeNode* solve(vector<int>& pre, vector<int>& in, int&index, int inStart, int inEnd, int n, map<int, int>& nodeToIndex){
        //index baahr jaaata h to
        if(index>=n || inStart>inEnd){
            return NULL;
        }
        //elem kaunsa h
        int elem = pre[index++];
        TreeNode* temp = new TreeNode(elem);
        // int pos = findPos(in, elem,n);
         int pos = nodeToIndex[elem];
        temp->left = solve(pre,in,index,inStart,pos-1,n,nodeToIndex);
        temp->right=solve(pre,in,index,pos+1,inEnd,n,nodeToIndex);
        return temp;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
         int n = preorder.size();
        map<int, int> nodeToIndex;
        
        //crteate node to index maqp
        mapping(inorder,n,nodeToIndex);
       
        
        TreeNode* ans =solve(preorder, inorder, preOrderIndex, 0, n-1,n,nodeToIndex);
        return ans;
    }
};