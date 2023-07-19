class Solution {
public:
    int searchNextNonOverlappingRide(vector<vector<int>>& rides, int start) {
        int left = start + 1;
        int right = rides.size() - 1;
        int nextNonOverlapIndex = rides.size();

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (rides[mid][0] >= rides[start][1]) {
                nextNonOverlapIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return nextNonOverlapIndex;
    }

    long long solve(vector<vector<int>>& rides, int index, vector<long long>& dp) {
        if (index >= rides.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        long long money = rides[index][1] - rides[index][0] + rides[index][2];

        int nextIndex = searchNextNonOverlappingRide(rides, index);
        long long maxsum = money + solve(rides, nextIndex, dp);
        long long maxsum2 = solve(rides, index + 1, dp);

        dp[index] = max(maxsum, maxsum2);
        return dp[index];
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<long long> dp(rides.size(), -1);

        return solve(rides, 0, dp);
    }
};
