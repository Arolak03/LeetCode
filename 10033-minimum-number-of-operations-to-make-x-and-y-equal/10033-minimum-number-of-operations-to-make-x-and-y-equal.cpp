class Solution {
public:
    
    int solve(int a, int b,vector<int>& dp){
        if(a<b)return b-a;
        if(a==b) return 0;
         // or any sufficiently large value
        if(dp[a]!=1e6)return dp[a];
        int div11 = 1e6, div5 = 1e6, dec = 1e6;
        
        if(!(a % 11)) div11 = 1 + solve(a / 11, b,dp);
        else div11=min(a%11+solve(a/11,b,dp)+1,(11-a%11)+solve(a/11+1,b,dp)+1);
        if(!(a % 5)) div5 = 1 + solve(a / 5, b,dp);
        else div5=min(a%5+solve(a/5,b,dp)+1,(5-a%5)+solve(a/5+1,b,dp)+1);
        dec = 1 + solve(a - 1, b,dp);
        
        return dp[a]=min({div11, div5, dec});
    }
    
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x == y) return 0;
        // if(y > x) return abs(y - x);
        vector<int> dp(1e4+100,1e6);
        return solve(x, y,dp);
    }
};
