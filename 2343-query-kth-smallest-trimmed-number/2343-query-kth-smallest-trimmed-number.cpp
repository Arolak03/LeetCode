class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int trim=queries[i][1];
            int kth=queries[i][0];
            int len=nums[0].length();
            int size=len-trim;
            priority_queue<pair<string, int>>pq;
            for(int j=0;j<nums.size();j++){
                // int len=nums[j].size();
                string temp=nums[j].substr(size,trim);
                if(pq.size()<kth){
                    pq.push({temp,j});
                }        
                else if(pq.top().first>temp){
                    pq.pop();
                    pq.push({temp,j});
                }
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};
