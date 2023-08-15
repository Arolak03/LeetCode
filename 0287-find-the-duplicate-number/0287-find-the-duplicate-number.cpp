class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int element=-1;
        int n = nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]==nums[j]){
        //             element  = nums[i];
        //             break;
        //         }
        //         // break;
        //     }
        // }
        // return element;
        // int element=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==nums[i+1]){
                element=nums[i];
                break;
            }
        }
        return element;
    }
};