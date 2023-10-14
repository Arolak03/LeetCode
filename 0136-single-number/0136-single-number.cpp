class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto& pair: mpp){
            if(pair.second==1){
                return pair.first;
            }
        }
        return 0;
    }
};