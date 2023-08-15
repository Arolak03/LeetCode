class Solution {
public:
    
    int solve(vector<int>& nums, int n, int i){
        long long maxi=INT_MIN;
        long long sum=0;
        if(i>=n){
            return 0;
        }
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
    
    int maxSubArray(vector<int>& nums) {
       int n = nums.size();
        return solve(nums,n,0);
    }
};