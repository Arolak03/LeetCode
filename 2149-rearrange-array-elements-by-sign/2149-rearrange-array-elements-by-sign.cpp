class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      int len=  nums.size();
      vector<int>arrange;
      int p = 0, n = 0;
  
      while(p<len and n<len){
        while(p<len && nums[p]<0)p++;
        while(n<len && nums[n]>=0)n++;
        arrange.push_back(nums[p]);
        arrange.push_back(nums[n]);
        p++;
        n++;
      }
      return arrange;
    }
};