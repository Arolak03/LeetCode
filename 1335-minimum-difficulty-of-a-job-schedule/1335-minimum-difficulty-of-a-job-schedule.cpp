class Solution {
private:
    int dp[300][1001];
    int f(int idx,int d,vector<int> &jobDifficulty) {
        //base cases
        if(idx == jobDifficulty.size() && d == 0) return 0;
        if(idx == jobDifficulty.size() || d == 0 || jobDifficulty.size() < d+idx) return 1e9;
        if(dp[idx][d] != -1) return dp[idx][d];
        

        int maxi=0,ans=1e9;
        for(int i=idx;i<jobDifficulty.size();++i) {
            maxi=max(maxi,jobDifficulty[i]);
            int res=f(i+1,d-1,jobDifficulty);
            if(res!=1e9) ans=min(ans,maxi+res);
        }
        return dp[idx][d]=ans;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        //edge case
        if(jobDifficulty.size() < d) return -1;
        memset(dp,-1,sizeof(dp));
        return f(0,d,jobDifficulty);
    }
};