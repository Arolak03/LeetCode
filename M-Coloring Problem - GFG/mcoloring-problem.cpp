//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool isSafe(int col, std::unordered_map<int, std::vector<int>>& adj, int index, std::unordered_map<int, int>& mpp) {
        for (auto neigh : adj[index]) {
            if (mpp.find(neigh) != mpp.end() && mpp[neigh] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int m, int v, std::unordered_map<int, int>& mpp, std::unordered_map<int, std::vector<int>>& adj, int index) {
        if (index == v) return true;
        for (int i = 1; i <= m; i++) {
            if (isSafe(i, adj, index, mpp)) {
                mpp[index] = i;
                if (solve(m, v, mpp, adj, index + 1)) return true;
                mpp.erase(index);
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        std::unordered_map<int, int> mpp;
        std::unordered_map<int, std::vector<int>> adj;
        for (int i = 0; i < 101; i++) {
             for (int j = 0; j < 101; j++){
                 if(!graph[i][j]){
                     continue;
                 }
                adj[i].push_back(j);
                adj[j].push_back(i);
             }
        }

        return solve(m, n, mpp, adj, 0);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends