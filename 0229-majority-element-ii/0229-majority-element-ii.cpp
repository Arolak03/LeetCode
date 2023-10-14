class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<int> ans;
        for(auto& pair: mpp){
            if(pair.second>nums.size()/3){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};