#include <climits>
#include <iostream>

class Solution {
public:
    bool isSquare(int x) {
        for (int i = 0; i * i <= x; i++) {
            if (i * i == x) return true;
        }
        return false;
    }

    int solve(int n, vector<int>& dp) {
        if (n==0) return 0;
        if (n<0) return INT_MAX;
        if(dp[n]!=-1)return dp[n];
        // if (i > n / 2) return INT_MAX;

//         int include = INT_MAX,exc=0;
//         if (isSquare(i)) {
//             // cout<<i<<" ";
//             include = 1 + solve(n, i, sum + i);
//         }
//         else{
//             exc = solve(n, i + 1, sum);
//         }
//         cout<<include<<" "<<exc<<endl;
        
//         return min(include, exc);
        int ans=INT_MAX;
        for(int m=1;m*m<=n;m++){
            ans=min(ans,1+solve(n-m*m,dp));
        }
        return dp[n]=ans;
        
    }

    int numSquares(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        // return solve(n, 1, 0);
        vector<int> dp(n+1,-1);
        if(isSquare(n))return 1;
        return solve(n,dp);
    }
};
