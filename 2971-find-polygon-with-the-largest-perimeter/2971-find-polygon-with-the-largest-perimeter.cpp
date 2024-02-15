class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        vector<long long> pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=nums[i]+pref[i-1];
        }
        for(int i=n-1;i>0;i--){
            if(pref[i-1]>nums[i])return pref[i];
        }
        return -1;
    }
};