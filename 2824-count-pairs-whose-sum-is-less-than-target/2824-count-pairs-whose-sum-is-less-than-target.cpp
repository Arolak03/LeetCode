#include <vector>
#include <algorithm>

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 1; i++) {
            int l = i + 1;
            int r = n - 1;
            
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[i] + nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            count += l - (i + 1);
        }
        
        return count;
    }
};
