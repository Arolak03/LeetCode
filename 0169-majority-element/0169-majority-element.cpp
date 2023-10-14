class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int maxFreq=0;
        int maxFreqEle=nums[0];
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(maxFreq<mpp[nums[i]]){
                maxFreqEle=nums[i];
                maxFreq=mpp[nums[i]];
            }
        }
        return maxFreqEle;
        
        
    }
};