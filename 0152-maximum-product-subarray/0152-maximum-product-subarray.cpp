class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int prod1=nums[0];
        int prod2=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
           int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        ans= max(prod1,ans);
        }
        return ans;
    }
};