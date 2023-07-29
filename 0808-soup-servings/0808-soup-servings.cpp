#include <cmath>

class Solution {
public:
    double solve(int n, int m, vector<vector<double>>& dp ) {
 if(n <= 0 && m <= 0) return 0.5;
    if(m <= 0) return 0;
    if(n <= 0) return 1;
        if(dp[n][m]!=-1){
            return dp[n][m]; 
        }
        
       double ans = 0;
        ans+=solve(n-100,m,dp);
        ans+=solve(n-75,m-25,dp);
        ans+=solve(n-50,m-50,dp);
        ans+=solve(n-25,m-75,dp);
        return dp[n][m]=ans * 0.25;
    }
    

    double soupServings(int n) {
        // Round up n to the nearest multiple of 25 to avoid overflow in recursion
        if(n>10000){
            return 1;
        } 
        // n = ceil((double)n / 25);
        vector<vector<double>> dp(n+1, vector<double>(n+1,-1));
       
        return solve(n,n,dp);
    }
};
