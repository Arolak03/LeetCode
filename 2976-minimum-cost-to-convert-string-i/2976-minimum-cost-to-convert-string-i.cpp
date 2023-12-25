class Solution {
public:
    
    void floyd(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost, vector<vector<long long>>& adj){
        int n =cost.size();
        for(int i=0;i<n;i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            adj[u][v]=min(adj[u][v],(long long)cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(adj[i][k] != INT_MAX && adj[k][j] != INT_MAX){
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long n=source.size();
        vector<vector<long long>> adj(26, vector<long long>(26, INT_MAX));
        floyd(source,target,original,changed,cost,adj);
        long long ans=0;
        for(int i=0;i<n;i++){
            if(source[i]==target[i])continue;
            // if(source[i]!=target[i]){
            if(adj[source[i]-'a'][target[i]-'a']==INT_MAX)return -1;
            ans+=adj[source[i]-'a'][target[i]-'a'];
            // }
        }
        return ans;
    }
};