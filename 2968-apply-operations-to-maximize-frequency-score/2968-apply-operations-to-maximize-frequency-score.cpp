class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int n =nums.size();
        int l=0;
        int r=1;
        if(n==1)return 1;
        vector<long long> prefsum(n+1,0);
        // prefsum[0]=nums[0];
        for(int i=0;i<n;i++){
            prefsum[i+1]=nums[i]+prefsum[i];
        }
        int score=INT_MIN;
        
        while(r<n){
            
            ++r;
            int m=(l+r)/2;
            long long target=nums[m];
            long long cost=((m-l)*target-(prefsum[m]-prefsum[l]))+(prefsum[r]-prefsum[m]-(r-m)*target);
            while(l<r && cost>k){
                
                ++l;
                m=(l+r)/2;
                target=nums[m];
                cost=((m-l)*target-(prefsum[m]-prefsum[l]))+(prefsum[r]-prefsum[m]-(r-m)*target);
                
            }
            score=max(score, r-l);
            
        }
        return score;
    }
};