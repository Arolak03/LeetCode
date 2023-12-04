class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0;
        int j=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]==1){
                while(i<nums.size() && nums[i]==1){
                    i++;
                }
                ans=max(ans,i-j);
            }
            j=i+1;
            i=i+1;
        }
        return ans;
    }
};