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
class Solution{
    public:

long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
        long long int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            ans = 0;
            while(n--){
                TreeNode* p = q.front();
                q.pop();
                ans += p->val;
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right); 
            }
            pq.push(ans);
            if(pq.size()>k){
                pq.pop();
            }
        }
        if(pq.size()<k)return -1;
        return pq.top();
    }
};