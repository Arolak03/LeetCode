class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n =nums.size();
        int sum=0;
        int maxLen=0;
        unordered_map<int, int> mpp;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            sum+= nums[i]==1? 1: -1;
            if(mpp.count(sum)){
                maxLen=max(maxLen,i-mpp[sum]);
            }
            else {
                mpp[sum]=i;
            }
        }
        return maxLen;
    }
};