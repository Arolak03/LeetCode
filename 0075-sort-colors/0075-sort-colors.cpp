class Solution {
public:
    
    void sorting(vector<int>& nums){
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int temp = nums[i];
                if(nums[i]>nums[j]){
                    nums[i]=nums[j];
                    nums[j]=temp;
                }
            }
            
        }
        // return nums;
    }
    void sortColors(vector<int>& nums) {
        sorting(nums);
        
    }
};