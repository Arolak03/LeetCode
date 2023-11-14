class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1;
        int ans=INT_MIN;
        int n =nums.size();
        int suffix=1;
        for(int i=0;i<n;i++){
            if(suffix==0)suffix=1;
            if(prefix==0)prefix=1;
            // pro1*=nums[i];
            
            prefix=prefix*nums[i];
            suffix=nums[n-i-1]*suffix;
            ans=max(ans,max(suffix,prefix));
            
        }
        return ans;
    }
};