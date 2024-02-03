class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n =nums.size();
        // vector<int> op;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(n%3!=0)return {};
        for(int i=0;i<n;i++){
            vector<int> op;
            int left=nums[i];
            int count=3;
            // cout<<i;
            int j=i;
            while(j<n && count>0 && abs(nums[j]-left)<=k){
                op.push_back(nums[j]);
                j++;
                count--;
            }
            // cout<<count<<" "<<j<<" ";
            // cout<<endl;
            if(count!=0)return {};
            ans.push_back(op);
            i=j-1;
        }
        return ans;
    }
};