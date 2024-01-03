class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> op(queries.size());
        for(int i=0;i<queries.size();i++){
            vector<pair<string,int>> ans;
            for(int j=0;j<nums.size();j++){
                string  mine=nums[j].substr(nums[j].size()-queries[i][1]);
                // cout<<mine<<" ";
                ans.push_back({mine,j});
            }
            sort(ans.begin(),ans.end());
            int kth=queries[i][0]-1;
            op[i]=(ans[kth].second);
        }
        for(auto it:op)cout<<it<<" ";

        return op;
    }
};