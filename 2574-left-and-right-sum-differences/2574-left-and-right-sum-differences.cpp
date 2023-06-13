class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int rightsum=0;
        
        for(int i=n-1;i>=0;i--){
            ans[i]=rightsum;
            rightsum=rightsum+nums[i];
            
        }
        int leftsum=0;
        for(int i=0;i<n;i++){
            ans[i]=abs(ans[i]-leftsum);
            leftsum=leftsum+nums[i];
        }
        return ans;
        
            
    }
};