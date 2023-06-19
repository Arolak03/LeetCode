class Solution {
public:
    int altitude(vector<int>& gain, vector<int>& total) {
        int n = gain.size();

        for (int i = 0; i < n; i++) {
            total[i + 1] = total[i] + gain[i];
        }

        int maxi = INT_MIN;
        for (int i = 0; i < n + 1; i++) {
            maxi = max(maxi, total[i]);
        }
        return maxi;
    }

    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> total(n + 1, 0);
        return altitude(gain, total);
    }
};
