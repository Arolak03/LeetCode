
    class Solution {
public:
    
    int subs(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        if(a.length()==i || b.length()==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            ans = 1+subs(a,b,i+1,j+1,dp);
        }
        else{
            ans = max(subs(a,b,i+1,j,dp),subs(a,b,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    
    int longestPalindromeSubseq(string s) {
        string b = s;
        reverse(b.begin(), b.end());
        vector<vector<int>> dp(s.length(), vector<int>(s.length(),-1));
        
        return subs(s, b,0,0,dp);
    }
};