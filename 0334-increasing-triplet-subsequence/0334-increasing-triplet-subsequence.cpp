class Solution {
public:
 bool increasingTriplet(vector<int>& nums) {


        
        int firstSmaller = INT_MAX, secondSmaller = INT_MAX;

        for(int i=0 ;i<nums.size() ;i++){

            if(firstSmaller>=nums[i])
            firstSmaller = nums[i];
            else if(secondSmaller>=nums[i])
            secondSmaller = nums[i];
            else
            return 1;
        }
        return 0;
    }
};