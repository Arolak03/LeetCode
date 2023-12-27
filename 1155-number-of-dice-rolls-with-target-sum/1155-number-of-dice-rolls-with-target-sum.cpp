class Solution {
public:
    #define mod 1000000007
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<long long>> dp(n+1, vector<long long>(target+1,-1));
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, 0));
        dp[0][0]=1;
        for(int dice=1;dice<=n;++dice){
            for(int curr=1;curr<=target;++curr){
                int ans = 0;

                for (int num = 1; num <= k; ++num) {
                    if (num <= curr)
                        ans = ((ans%mod) + (dp[dice - 1][curr - num] % mod)) % mod;
                }

                dp[dice][curr] = (ans % mod);
            
            }
        }
        
        return dp[n][target];
    }
};