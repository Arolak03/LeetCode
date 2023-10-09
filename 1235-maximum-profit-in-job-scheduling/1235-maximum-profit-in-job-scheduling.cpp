class Solution {
public:
    int valid(vector<vector<int>>& my, int l, int end) {
        int r = my.size() - 1;
        int result = -1; // Change this to -1
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (my[mid][0] >= end) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& my, int index, vector<int>& dp) {
        if (index >= my.size()) {
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        // include

        int next = valid(my, index + 1, my[index][1]);
        int include = my[index][2] + solve(my, next,dp);
        int exc = solve(my, index + 1,dp);
        return dp[index]=max(include, exc);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> my(profit.size(), vector<int>(3, 0));
        vector<int> dp(my.size()+1,-1);
        for (int i = 0; i < profit.size(); i++) {
            my[i][0] = startTime[i];
            my[i][1] = endTime[i];
            my[i][2] = profit[i];
        }
        // include
        auto comp = [&](auto&  vec1, auto& vec2){
            return vec1[0]<=vec2[0];
        };
        sort(my.begin(),my.end(),comp);
        return solve(my, 0,dp);
    }
};
