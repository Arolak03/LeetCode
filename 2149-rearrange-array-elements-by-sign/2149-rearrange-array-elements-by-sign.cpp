class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)arr1.push_back(nums[i]);
            if(nums[i]>0)arr2.push_back(nums[i]);
        }
        int index1=0;
        int index2=0;
        for(int i=0;i<nums.size()-1;i+=2){
            nums[i]=arr2[index2++];
            nums[i+1]=arr1[index1++];
        }
        // if(nums.size()==2){
        //     if(nums[0]<0){
        //         swap(nums[0],nums[1]);
        //     }
        // }
        
        return nums;
    }
};