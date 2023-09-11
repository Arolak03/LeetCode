class Solution {
public:
    // hash map
    unordered_map<int, int> mpp;
    
    int solve(vector<int>& stones, int n, int index, int prevJump, vector<vector<int>>& dp) {
        if (index >= n - 1) {
            return 1;  // Successfully crossed the river
        }
        if (dp[index][prevJump] != -1) {
            return dp[index][prevJump];
        }
        
        bool ans = false;
        // Try all possible next jumps: k-1, k, k+1
        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            if (nextJump > 0 && mpp.find(stones[index] + nextJump) != mpp.end()) {
                ans = ans || solve(stones, n, mpp[stones[index] + nextJump], nextJump, dp);
            }
        }
        
        return dp[index][prevJump] = ans;
    }
    
    bool canCross(vector<int>& stones) {
        for (int i = 0; i < stones.size(); i++) {
            mpp[stones[i]] = i;
        }
        
        if (stones[1] != 1) {
            return false;  // Special case: the second stone is unreachable from the first stone
        }
        
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), -1));
        return solve(stones, stones.size(), 0, 0, dp);  // Start from the second stone with a jump of 1.
    }
};
