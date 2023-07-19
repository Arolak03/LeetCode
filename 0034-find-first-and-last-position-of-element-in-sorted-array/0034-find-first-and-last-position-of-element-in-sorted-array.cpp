class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int i=0;
        int end=nums.size()-1;
        while(i<end){
            if(nums[i]==target){
                ans.push_back(i);
                break;
            }
            i++;
        }
        while(end>=0){
            if(nums[end]==target){
                ans.push_back(end);
                break;
            }
            end--;
        }
        if(ans.empty()){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        if(ans.size()==1){
            ans.push_back(ans[0]);
        }
        return ans;
    }
};