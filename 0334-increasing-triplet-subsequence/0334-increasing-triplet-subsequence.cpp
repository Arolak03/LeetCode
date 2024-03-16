class Solution {
public:
    
    void nxt(vector<int>& nums, vector<int>& next){
        int n = nums.size();
        stack<int> s;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i])s.pop();
            if(!s.empty())next[i]=s.top();
            s.push(i);
        }
    }
    void prevv(vector<int>& nums, vector<int>& prev){
        int n =nums.size();
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;i++){
            while(!s.empty() && nums[s.top()]>=nums[i])s.pop();
            if(!s.empty())prev[i]=s.top();
            s.push(i);
        }
    }
    
    
    bool increasingTriplet(vector<int>& nums) {
        int n =nums.size();
        vector<int> prev(n,-1);
        vector<int> next(n,-1);
        nxt(nums,next);
        prevv(nums,prev);
        for(int i=0;i<n;i++){
            if(prev[i]!=-1 && next[i]!=-1)return true;
        }
        return false;
    }
};