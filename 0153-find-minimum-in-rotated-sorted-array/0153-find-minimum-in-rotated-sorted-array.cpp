class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int elem=INT_MAX;
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[l]<=nums[mid]){
                //left is sorted
                //right m hoga 
                elem=min(elem, nums[l]);
                l=mid+1;
            }
            else{
                elem=min(elem, nums[mid]);
                r=mid-1;
            }
            
        }
        return elem;
    }
};