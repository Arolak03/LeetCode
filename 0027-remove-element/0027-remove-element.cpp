class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int n =nums.size();
        int count=0;
    
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                // count++;
                nums[count]=nums[i];
                count++;
            }
            
        }

        return count;
    }
};