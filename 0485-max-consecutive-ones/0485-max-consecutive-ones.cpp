class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int start=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1){
                start=i+1;
                
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};