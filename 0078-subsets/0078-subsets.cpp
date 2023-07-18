class Solution {
public:
    void solve(vector<int>& nums,vector<int> output,vector<vector<int>>& ans,int index){
        if(index==nums.size()){
            ans.push_back(output);
            return;
        }
       
        
         solve(nums,output,ans,index+1);
        // vector<vector<int>> ans;
        //include
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,ans,index+1);
        
        //exclude3
       
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums,output,ans,0);
        return ans;
    }
};