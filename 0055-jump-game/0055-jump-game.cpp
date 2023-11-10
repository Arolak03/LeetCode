class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;

        for (int i = 0; i < n; ++i) {
            if (i > maxReach) {
                return false;  // If you can't reach the current position, return false
            }
            maxReach = max(maxReach, i + nums[i]);

            if (maxReach >= n - 1) {
                return true;  // If you can reach the end, return true
            }
        }

        return false;
    }
};
