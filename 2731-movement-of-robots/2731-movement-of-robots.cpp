class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n=nums.size();
            
        for(int i=0;i<n;i++){
            if(s[i]=='R')nums[i]+=d;
            else{nums[i]-=d;}
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        vector<long long> prefs(n,0);
        prefs[0]=nums[0];//coordinates aagye
        for(int i=1;i<n;i++){
            prefs[i]=prefs[i-1]+nums[i];}
            
        for(long long i=1;i<n;i++){
            ans+= (i*(long long)nums[i])-prefs[i-1];
            ans%=(long long)1e9+7;
        }
        return ans;
        
    }
};