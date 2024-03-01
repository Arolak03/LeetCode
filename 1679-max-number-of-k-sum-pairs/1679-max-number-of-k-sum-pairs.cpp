class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        sort(nums.begin(), nums.end());
        int i=0;
        int j=n-1;
        while(i<j){
            if(nums[i]+nums[j]==k){
                ans++;
                i++;
                j--;
            }
            else if(nums[i]+nums[j]>k){
                j--;
            }
            else i++;
        }
        return ans;
    }
};