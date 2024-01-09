class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n =nums.size();
        int x=nums[nums.size()/2];
        for(auto it: nums){
            ans+=abs(x-it);
        }
        return ans;
    }
};