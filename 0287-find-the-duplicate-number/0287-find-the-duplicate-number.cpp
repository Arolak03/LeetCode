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
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++){
        //     if(nums[i]==nums[i+1]){
        //         element=nums[i];
        //         break;
        //     }
        // }
        // return element;
        vector<int>freq (n+1);
     
        for(int i=0;i<n;i++){
            if(freq[nums[i]]==0){
                freq[nums[i]]+=1;
            }
            else{
                return nums[i];
            }
        }
        return 0;
    }
};