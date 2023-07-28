#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    
        long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> costs(n);
        for (int i = 0; i < n; i++) {
            costs[i] = (long long)i * x;
        }
        
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            for (int j = 0; j < n; j++) {
                curr = min(curr, nums[(i + j) % n]);
                costs[j] += curr;
            }
        }
        
        return *min_element(costs.begin(), costs.end());
    }
};
