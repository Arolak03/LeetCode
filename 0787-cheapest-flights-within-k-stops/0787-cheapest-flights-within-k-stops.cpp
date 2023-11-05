class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        int edges = flights.size();
        for(int i=0; i<edges; i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n, numeric_limits<int>::max());
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (stops <= k && !q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [node, distance] = q.front();
                q.pop();
                for (auto& [neighbour, price] : adj[node]) {
                    if (price + distance < dist[neighbour]) {
                        dist[neighbour] = price + distance;
                        q.push({neighbour, dist[neighbour]});
                    }
                }
            }
            stops++;
        }
        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }
};