class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        multiset<int> ans;
        vector<int> mine;
        for(int i=0;i<nums.size();i++)ans.insert(nums[i]*nums[i]);
        for(auto it: ans)mine.push_back(it);
        return mine;
    }
};