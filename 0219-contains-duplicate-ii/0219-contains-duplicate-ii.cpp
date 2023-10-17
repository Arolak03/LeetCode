class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int n = nums.size();
//         int i1=0;
//         int i2=0;
//         for(int i=0;i<n;i++){
//             for(int j=n-1;j>i;j--){
//                 if(nums[i]==nums[j]){
//                     i1=i;
//                     i2=j;
//                     break;
//                 }
//             }
//         }
//         if(abs(i1-i2)<=k)return true;
                   
//         return false;
//         unordered_map<pair<int, int>. int> mpp;
//         for(int i=0;i<nums.size();i++){
//             mpp({nums[i],i})++;
//         }
        vector<pair<int, int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<nums.size()-1;i++){
            if(v[i].first==v[i+1].first && abs(v[i].second-v[i+1].second)<=k)return true;
        }
        
        return false;
        
        
    }
};