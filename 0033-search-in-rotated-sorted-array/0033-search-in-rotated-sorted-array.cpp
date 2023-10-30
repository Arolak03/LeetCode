class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n =nums.size();
        int l=-0;
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            // mid hi ho
            if(nums[mid]==target)return mid;
            //kaunsa sorted 
            if(nums[mid]>=nums[l]){
                //left sorted
                //target kaunse half m;
                if(nums[mid]>=target && nums[l]<=target){
                    r=mid-1;
                }
                else l=mid+1;
            }
            //right sorted;
            else{
                if(target>=nums[mid] && target<=nums[r]){
                    l=mid+1;
                }
                else {
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};