class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0 || k <= 0) return false;
        int n = nums.size();
        multiset<long long> window;

        for (int right = 0; right < n; right++) {
            if (right > k) window.erase(nums[right - k - 1]);
            auto safe = window.lower_bound(static_cast<long long>(nums[right]) - t);
            if (safe != window.end() && *safe <= static_cast<long long>(nums[right]) + t) {
                return true;
            }
            window.insert(nums[right]);
        }

        return false;
    }
};
