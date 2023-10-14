class Solution {
public:
    
    void solve(vector<vector<int>>& ans, vector<int>& nums,int freq[],vector<int>& op, int index){
        if(op.size()==nums.size()){
            ans.push_back(op);
            return;
        }
        // daalna
        for(int i=0;i<nums.size();i++){
            // agr dala nhi h 
            if(!freq[i]){
                op.push_back(nums[i]);
                freq[i]=1;
                solve(ans,nums,freq,op,index+1);
                freq[i]=0;
                op.pop_back();
            }
            // swap(nums[i],nums[index]);
            // solve(ans,index+1,nums);
            // swap(nums[i],nums[index]);
        }
    }
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n =nums.size();
        vector<int> op;
        int freq[n];
        for(int i=0;i<n;i++){
            freq[i]=0;
        }
        solve(ans, nums,freq,op,0);
        return ans;
    }
};