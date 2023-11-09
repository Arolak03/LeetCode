class Solution {
public:
    
    bool solve(string& s, int i, int j, vector<vector<int>>& dp){
        if(i>=j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=solve(s,i+1,j-1,dp);
        return dp[i][j]=0;
    }
    
    string longestPalindrome(string s) {
        int n=s.length();
        int maxi=0;
        int sp=0;
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        // string m ="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               if(solve(s,i,j,dp)){
                   if(j-i+1>maxi){
                       maxi=j-i+1;
                       sp=i;
                   }
               }
            }
        }
        return s.substr(sp,maxi);
    }
};