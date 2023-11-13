class Solution {
public:
    
    
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=1;
        int n =nums.size();
        int ans=1;
        for(int i=0;i<n-1;i++){
            // int ans=1;
            if(nums[i]==nums[i+1])continue;
            if(nums[i]+1==nums[i+1]){
                ans++;
            }
            else ans=1;
            maxi=max(maxi,ans);
        }
        if(n==0)return 0;
        return maxi;
        
    }
};