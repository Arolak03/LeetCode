class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp1, mpp2;
        for(int i=0;i<nums1.size();i++){
            mpp1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            mpp2[nums2[i]]++;
        }
        vector<vector<int>> ans;
        vector<int> temp1;
        vector<int> temp2;
        for(auto it: mpp1){
            
            if(mpp2.find(it.first)==mpp2.end()){
                temp1.push_back(it.first);
            }
        }
        for(auto it: mpp2){
            if(mpp1.find(it.first)==mpp1.end())temp2.push_back(it.first);
        }
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};