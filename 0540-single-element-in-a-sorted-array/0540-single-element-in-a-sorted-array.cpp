class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int index=-1;
        if(n==1){
            return nums[0];
        }
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1] || nums[i]==nums[i+1]){
                // i+=2;
            }
            else{
                index=nums[i];
                break;
            }
        }
        if(index==-1){
            index=nums[0];
        }
        return index;
    }
};