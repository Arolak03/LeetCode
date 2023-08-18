class Solution {
public:
    
    void solve(vector<int>& nums, int index, set<vector<int>>& sub, vector<int>& op){
        // vector<int> op;
        if(index>=nums.size()){
            sub.insert(op);
            return;
        }
        op.push_back(nums[index]);
        solve(nums,index+1,sub,op);
        op.pop_back();
        solve(nums,index+1,sub,op);
    
}
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> subarray;
        vector<int> op;
        solve(nums, 0, subarray,op);
        vector<vector<int>> temp;
            for(auto it: subarray){
                temp.push_back(it);
            }
        return temp;
    }
};