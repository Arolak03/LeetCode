class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // set<int> ans;
        vector<int> mine;
        for(int i=0;i<nums.size();i++)mine.push_back(nums[i]*nums[i]);
        sort(mine.begin(),mine.end());
        return mine;
    }
};