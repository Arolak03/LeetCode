class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();
     set<int>ss(nums.begin(),nums.end());
        if(valueDiff==0 && ss.size()==nums.size())return false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && j <= i + indexDiff; j++) {
            if (abs(static_cast<long long>(nums[i]) - nums[j]) <= valueDiff) {
                return true;
            }
        }
    }

    return false;

        
    //   unordered_map<int, int> mpp;
    //   for (int i = 0; i < n; i++) {
    //       for(int j=0;j<=valueDiff;j++){
    //       auto iter = mpp.find(nums[i] + j);
    //       if (iter != mpp.end()) {
    //          int index = iter->second;
    //          if (abs(i - index) <= indexDiff) {
    //             return true;
    //          }  
    //       }
    //       mpp[nums[i] + j] = i;
    //       }
    // }
    // return false;
    }
};