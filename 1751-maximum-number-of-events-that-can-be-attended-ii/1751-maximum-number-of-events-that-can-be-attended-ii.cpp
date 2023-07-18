class Solution {
public:
    int solve(const vector<vector<int>>& events, int k, int index, vector<vector<int>>& dp) {
        if (index >= events.size() || k == 0) {
            return 0;
        }

        if (dp[index][k] != -1) {
            return dp[index][k];
        }

        // Include the current event
        int sum = events[index][2];
        int nextEventIndex = index + 1;
        while (nextEventIndex < events.size() && events[nextEventIndex][0] <= events[index][1]) {
            nextEventIndex++;
        }
        int maxsum = sum + solve(events, k - 1, nextEventIndex, dp);

        // Exclude the current event
        int maxsumWithoutCurrent = solve(events, k, index + 1, dp);

        dp[index][k] = max(maxsum, maxsumWithoutCurrent);
        return dp[index][k];
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
    

        // Initialize dp with -1
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));

        return solve(events, k, 0, dp);
    }
};
