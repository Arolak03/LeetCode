class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
            // adj[v].push_back({u,w});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int, int>> q;
        q.push({src,0});
        int rounds=0;
        while(!q.empty() && rounds<=k){
            int sz=q.size();
            while(sz--){
                int node=q.front().first;
                int distance=q.front().second;
                q.pop();
                for(auto it: adj[node]){
                    int dd=it.second;
                    int nn=it.first;
                    if(dd+distance<dist[nn]){
                        // if(dist[nn]!=INT_MAX){
                            dist[nn]=dd+distance;
                            q.push({nn,dist[nn]});
                            // rounds++;
                        // }
                    }
                    
                }
            }
            rounds++;
        }
        return dist[dst]==INT_MAX? -1: dist[dst];
        
        
    }
};