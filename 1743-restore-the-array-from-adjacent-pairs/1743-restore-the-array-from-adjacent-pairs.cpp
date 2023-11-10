class Solution {
public:
    void solve(vector<int>& arr, unordered_map<int, bool>& vis, unordered_map<int, vector<int>>& adj, int root, int prev) {
        arr.push_back(root);
        // vis[root] = 1;
        for (int neigh : adj[root]) {
            // if (!vis[neigh] && neigh!=prev) {
            if (neigh!=prev) {

                solve(arr, vis, adj, neigh,root);
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int e = adjacentPairs.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < e; i++) {
            int u = adjacentPairs[i][0];
            int v = adjacentPairs[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int root=0;
        for (auto& it : adj) {
            if (it.second.size() == 1) {
                root = it.first;
                break;
            }
        }
        vector<int> dfs;
        unordered_map<int, bool> vis;
        cout << root;
        // for (int i = 0; i < adj.size(); i++) {
            // if(!vis[i])
            solve(dfs, vis, adj, root,INT_MAX);
        // }
        return dfs;
    }
};
