class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n =nums.size();
        int high=n-1;
        int low=0;
        int i=0;
        int mid=0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
                
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
            else{
                mid++;
            }
            // i++;
        }
    }
};