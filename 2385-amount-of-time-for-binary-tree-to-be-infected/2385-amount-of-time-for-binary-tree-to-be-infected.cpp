class Solution {
public:
    void findPar(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& par) {
        queue<TreeNode*> q;
        q.push(root);
        par[root] = nullptr;
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left) {
                q.push(temp->left);
                par[temp->left] = temp;
            }
            if (temp->right) {
                q.push(temp->right);
                par[temp->right] = temp;
            }
        }
    }

    TreeNode* find(TreeNode* root, int x) {
        if (root == nullptr) return nullptr;
        if (root->val == x) return root;
        TreeNode* leftResult = find(root->left, x);
        if (leftResult != nullptr) return leftResult;  // If found in the left subtree, return

        return find(root->right, x);  // Check the right subtree
    }

    int amountOfTime(TreeNode* root, int start) {
        //find node
        TreeNode* target = find(root, start);
        unordered_map<TreeNode*, TreeNode*> par;
        findPar(root, par);

        // bfs karna hai
        queue<TreeNode*> q;
        int count = 0;
        q.push(target);
        unordered_map<TreeNode*, bool> vis;
        vis[target] = true;
        while (!q.empty()) {
            int n=q.size();
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                vis[temp]=true;
                if (temp->left && !vis[temp->left]) {
                    q.push(temp->left);
                    vis[temp->left] = true;
                }
                if (temp->right && !vis[temp->right]) {
                    q.push(temp->right);
                    vis[temp->right] = true;
                }
                if (par.find(temp) != par.end() && par[temp] != nullptr && !vis[par[temp]]) {
                    q.push(par[temp]);
                    vis[par[temp]] = true;
                }
            }
            count++;
        }

        return count-1;
    }
};















// class Solution {
// public:
//     int amountOfTime(TreeNode* root, int start) {
//         int time = 0;    
        
//         unordered_map<TreeNode*,TreeNode*> parent;
//         FindParent(root,parent);
        
//         TreeNode* target = Find(root,start);
        
//         queue<TreeNode*> q;
//         unordered_map<TreeNode*, bool> vis;       

//         q.push(target);
//         vis[target] = true;

//         while(!q.empty())
//         {
//             int n = q.size();
//             while(n--)
//             {
//                 auto front = q.front();
//                 q.pop();
//                 vis[front] = true;

//                 if(front->left and !vis[front->left])
//                 {
//                     q.push(front->left);
//                     vis[front->left] = true;
//                 }

//                 if(front->right and !vis[front->right])
//                 {
//                     q.push(front->right);
//                     vis[front->right] = true;
//                 }

//                 if(parent[front] and !vis[parent[front]])
//                 {
//                     q.push(parent[front]);
//                     vis[parent[front]] = true;
//                 }
//             }
//             time++;
//         }
//         return time-1;
//     }    
// private:
//     TreeNode* Find(TreeNode* node, int key) 
//     {
//         if(node== NULL) return NULL;

//         if(node->val == key) return node;        
//         else {
//             TreeNode* foundNode = Find(node->left,key);
//             if(!foundNode) foundNode = Find(node->right,key);              
//             return foundNode;
//         }
//     }
//     void FindParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent)
//     {
//         if(!root)return;
//         if(root->left) parent[root->left] = root;     
//         if(root->right) parent[root->right] = root;
//         FindParent(root->left,parent);
//         FindParent(root->right,parent);
//     }
// };