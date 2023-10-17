class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int, int> mpp;
//         for(int i=0;i<nums.size();i++){
//             mpp[nums[i]]++;
            
//         }
//         int count2=0;
//         for(int i=0;i<mpp.size();i++){
//             if(mpp[i]>=2){
//                 return true;
//             }
//         }
//         // if(count2==0)return false;
//         return false;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])return true;
        }
        return false;
        
        
    }
};