class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int n =nums.size();
        int count=0;
        // vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                // count++;
                nums[count]=nums[i];
                count++;
            }
            // else ans.push_back(nums[i]);
        }
        // nums=ans;
        return count;;
    }
};