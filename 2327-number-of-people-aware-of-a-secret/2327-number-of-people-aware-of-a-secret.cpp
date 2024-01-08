class Solution {
public:
    #define MOD 1000000007
    int solve(int n, int d, int f, int index,vector<int>& dp){
        if(index+d>n)return 1;
        if(dp[index]!=-1)return dp[index];
        int ans=1;
        for(int i=index+d;i<=min(n,f+index);i++){
            if(i==index+f){
                ans--;
                break;
            }
            ans=ans%MOD+solve(n,d,f,i,dp)%MOD;
        }
        return dp[index]=ans%MOD;
    }
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1,-1);
        return solve(n,delay,forget,1,dp)%MOD;
    }
};

// 1 














//class Solution {
// int dp[1001];
// #define mod 1000000007
// public:
//     int solve(int idx,int d,int f,int n){
//         if(idx+d>n)return 1;
//         if(dp[idx]!=-1)return dp[idx];
//         int ans=1;
//         for(int i=idx+d;i <= min(n,idx+f);i++){
//             if(i==idx+f){
//                 ans-=1;
//                 break;
//             }
//             ans= (ans%mod + solve(i,d,f,n)%mod)%mod;
//         }
//         return dp[idx]=ans;
//     }
//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         memset(dp,-1,sizeof(dp));
//        return solve(1,delay,forget,n); 
//     }
// };