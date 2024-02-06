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
    int countPairs(TreeNode* root, int distance) {
        //adj list bnanai h
        queue<TreeNode*> q;
        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        vector<TreeNode*> leaf;
        q.push(root);
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            if(top->left==top->right)leaf.push_back(top);
            if(top->left){
                mp[top].push_back(top->left);
                mp[top->left].push_back(top);
                q.push(top->left);
            }
            if(top->right){
                mp[top].push_back(top->right);
                mp[top->right].push_back(top);
                q.push(top->right);
            }
        }
        int ans=0;
        for(auto leaves: leaf){
            unordered_map<TreeNode*, int> vis;
            queue<pair<TreeNode*, int>>qq;
            qq.push({leaves,0});
            while(!qq.empty()){
                auto temp=qq.front();
                qq.pop();
                vis[temp.first]=1;
                for(auto it: mp[temp.first]){
                    if(vis[it])continue;
                    vis[it]=1;
                    int dist=temp.second;
                    if(distance>=dist+1){
                        if(!it->left && !it->right)ans++;
                        else{
                            qq.push({it,dist+1});
                        }
                    }
                }
            }
        }
        return ans/2;
        
    }
};