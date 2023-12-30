typedef long long int ll;
const ll NO_VALUE = 1e9;

class Solution {
    int n;
    vector<vector<int>> g;
    vector<int> cost;
    
    vector<vector<ll>> val;
    vector<ll> coins;
    
    void CalculateCoins (int src, int par) {
        vector<ll> child_val = {cost[src]};
        
        for (auto i : g[src]) {
            if (i == par) continue;
            
            CalculateCoins (i, src);
            for (auto i : val[i]) child_val.push_back(i);
        }
        sort (child_val.begin(), child_val.end());
        
        if (child_val.size() < 3) {
            coins[src] = 1;
            val[src] = child_val;
        }
        else {
            int n = child_val.size();        
            ll max_product = -1e18;
            max_product = max (max_product, child_val[0]*child_val[1]*child_val[n-1]);
            max_product = max (max_product, child_val[n-1]*child_val[n-2]*child_val[n-3]);
    
            coins[src] = max_product < 0? 0 : max_product;
            
            if (child_val.size() < 6) val[src] = child_val;
            else val[src] = {child_val[0], child_val[1], child_val[n-3], child_val[n-2], child_val[n-1]};
        }
    }
    
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& _cost) {
        n = _cost.size();
        
        g.clear(), val.clear(), cost.clear(), coins.clear(); 
        val.resize(n), g.resize(n), cost.resize(n), coins.resize(n);
        cost = _cost;
        
        for (auto e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        CalculateCoins(0, -1);
        return coins;
    }
};
