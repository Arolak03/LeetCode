class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int> ans(n,1);
        int n = nums.size();
        vector<int> left(n,1);
        // int n =nums.size();
        vector<int> ans(n,1);
        vector<int> right(n,1);
        right[n-1]=nums[n-1];
        left[0]=nums[0];
        for(int i=1;i<n;i++){
            left[i]=nums[i]*left[i-1];
            right[n-i-1]=right[n-i]*nums[n-i-1];
        }
        for(int i=1;i<n-1;i++){
            ans[i]=left[i-1]*right[i+1];
        }
        ans[0]=right[1];
        ans[n-1]=left[n-2];
        return ans;
    }
};