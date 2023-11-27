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
    
    void par(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        // if(root==NULL)return;
        queue<TreeNode*>q;
        q.push(root);
        // parent[root]=NULL;
        while(!q.empty()){
            
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    parent[temp->left]=temp;
                }
                if(temp->right){
                    parent[temp->right]=temp;
                    q.push(temp->right);
                }   
        }
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        par(root, parent);
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool> vis;
        vis[target]=true;
        int count=0;
        
        while(!q.empty()){
            int sz=q.size();
            if(count==k)break;
            for(int i=0;i<sz;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left]=true;
                }
                if(temp->right && !vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right]=true;
                }
                if(parent[temp] && !vis[parent[temp]]){
                    q.push(parent[temp]);
                    vis[parent[temp]]=true;
                }
                
            }
            count++;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};