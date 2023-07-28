class Solution {
public:
    
    int solve(vector<int>& nums, int l, int r, int n){
        if(l==r){
            return nums[l];
        }
        int scorer = nums[r]-solve(nums,l,r-1,n);
        int scorel=nums[l]-solve(nums,l+1,r,n);
        return max(scorer,scorel);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        return solve(nums,0,n-1,n) >=0;
        
    }
};