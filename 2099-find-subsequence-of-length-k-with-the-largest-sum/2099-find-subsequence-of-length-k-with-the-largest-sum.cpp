class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if(k==nums.size())return nums;
        vector<pair<int, int>> mpp;
        int n =nums.size();
        for(int i=0;i<n;i++){
            mpp.push_back({nums[i],i});
        }
        sort(mpp.begin(), mpp.end());
        vector<int> ind;
        int i=n-1;
        for(int j=0;j<k;j++){
            ind.push_back(mpp[i].second);
            i--;
        }
        sort(ind.begin(),ind.end());
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i]=nums[ind[i]];
        }
        return ans;
    }
};