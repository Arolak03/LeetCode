class Solution {
public:
    
    int solve(vector<int>& nums, int n) {
    // int n = nums.size();
    if (n == 0) {
        return 0;
    }
    
    int max_ending_here = nums[0];
    int max_so_far = nums[0];
    
    for (int i = 1; i < n; ++i) {
        max_ending_here = max(nums[i], nums[i] + max_ending_here);
        max_so_far = max(max_so_far, max_ending_here);
    }
    
    return max_so_far;
}
    
    int maxSubArray(vector<int>& nums) {
       int n = nums.size();
        return solve(nums,n);
    }
};