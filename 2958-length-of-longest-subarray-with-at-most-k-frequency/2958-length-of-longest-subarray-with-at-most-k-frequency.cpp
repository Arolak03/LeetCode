class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int j=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]==k){
                while(j<nums.size() && mpp[nums[i]]==k){
                    mpp[nums[j]]--;
                    j++;
                    cout<<nums[j]<<" ";
                }
            }
            mpp[nums[i]]++;
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};