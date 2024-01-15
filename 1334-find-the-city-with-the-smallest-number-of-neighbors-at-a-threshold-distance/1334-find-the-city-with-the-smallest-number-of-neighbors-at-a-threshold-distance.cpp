#include <vector>
#include <unordered_map>
#include <climits>

class Solution {
public:
    // void minSpan(vector<vector<int>>& mpp, vector<vector<int>>& e, int n) {

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mpp(n,vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mpp[i][j] = i == j ? 0 : 10001;
            }
        }
        for (auto &e : edges) {
            mpp[e[0]][e[1]] = mpp[e[1]][e[0]] = e[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mpp[i][j] = min(mpp[i][j], mpp[i][k] + mpp[k][j]);
                }
            }
        }
        
       int res = -1, resCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (mpp[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= resCount) {
                resCount = count;
                res = i;
            }
        }
        return res;
    }
};
