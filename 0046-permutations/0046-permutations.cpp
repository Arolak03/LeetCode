class Solution {
public:
    
    void solve(vector<vector<int>>& ans, vector<int>& op, int index, vector<int>& nums){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        // daalna
        for(int i=index;i<nums.size();i++){
            // agr dala nhi h 
            // if(!freq[i]){
            //     op.push_back(nums[i]);
            //     freq[i]=1;
            //     solve(ans,op,freq,nums);
            //     freq[i]=0;
            //     op.pop_back();
            // }
            swap(nums[i],nums[index]);
            solve(ans,op,index+1,nums);
            swap(nums[i],nums[index]);
        }
    }
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n =nums.size();
        vector<int> op;
        // int freq[n];
        // for(int i=0;i<n;i++){
            // freq[i]=0;
        // }
        solve(ans,op,0, nums);
        return ans;
    }
};