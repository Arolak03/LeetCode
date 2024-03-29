class Solution {
public:
    long long ans=0;
    long long dfs(int node,vector<vector<int>>& adj, vector<bool>& vis,int seats){
        // node ko vis
        vis[node]=true;
        long long count=1;
        for(auto child: adj[node]){
            if(!vis[child]){
                count+=dfs(child,adj,vis,seats);
            }
        }
        long long x = ceil((double)count/seats);
        // if(count%seats)x++;
        if(node!=0){
            ans+=x;
        }
        return count;
        
    }
    
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // adj bnaao
        int n= roads.size()+1;
        if(roads.size()==0){
            return 0;
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<roads.size();i++){
            int v = roads[i][0];
            int u = roads[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        vector<bool> vis(n,0);
        dfs(0,adj,vis,seats);
        return ans;
    }
};