class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index!=-1){
            for(int j=n-1;j>=0;j--){
                if(nums[j]>nums[index]){
                    swap(nums[index],nums[j]);
                    break;
                }
            }
        
        // reverse(nums.begin()+index+1,nums.end());
        }
        // swap(nums[n-1],nums[n-2]);
        reverse(nums.begin()+index+1,nums.end());
    }
};
