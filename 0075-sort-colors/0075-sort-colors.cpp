class Solution {
public:
    
    void sorting(vector<int>& nums){
        int n = nums.size();
       int high = n-1;int low=0;int mid=0;
        while(high>=mid){
            if(nums[mid]==2){
                swap(nums[high],nums[mid]);
                high--;
            }
            else if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else{
                mid++;
                // low++
            }
        }
        // return nums;
    }
    void sortColors(vector<int>& nums) {
        sorting(nums);
        
    }
};