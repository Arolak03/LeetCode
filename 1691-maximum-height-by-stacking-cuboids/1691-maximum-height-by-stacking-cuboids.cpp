class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        
        // Sorting the cuboids based on their dimensions in non-decreasing order
        for (auto &cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        
        // Initializing the dynamic programming array
        vector<int> dp(n, 0);
        
        // Filling the dp array
        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2]; // Height of the current cuboid
            
            for (int j = 0; j < i; j++) {
                if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }
        
        // Finding the maximum height in the dp array
        int maxHeight = 0;
        for (int i = 0; i < n; i++) {
            maxHeight = max(maxHeight, dp[i]);
        }
        
        return maxHeight;
    }
};
