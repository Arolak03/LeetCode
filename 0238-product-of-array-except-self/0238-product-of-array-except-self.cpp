#include <vector>
#include <set>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod1 = 1;
        int prod2 = 1;

        // Check if there is more than one zero in the vector
        int zeroCount = count(nums.begin(), nums.end(), 0);
        if (zeroCount >1 ) {
            return vector<int>(n, 0);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) prod1 *= nums[i];
            prod2 *= nums[i];
        }

        vector<int> ans(n, prod1);
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                ans[i] = prod2 / nums[i];
            } else {
                ans[i] = prod1;
            }
        }

        return ans;
    }
};
