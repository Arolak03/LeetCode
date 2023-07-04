#include <vector>
#include <unordered_map>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> digitCount;
        
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            digitCount[temp]++;
        }
        
        int dig = 0;
        for (auto it = digitCount.begin(); it != digitCount.end(); it++) {
            if (it->second != 3) {
                dig = it->first;
                break;
            }
        }
        
        return dig;
    }
};
