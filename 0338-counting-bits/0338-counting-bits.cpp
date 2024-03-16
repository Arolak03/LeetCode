class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0); // dp array to store results
    if(n==0)return {0};
    // Base cases (0 and 1 have 0 and 1 set bits, respectively)
    dp[0] = 0;
    dp[1] = 1;

    // Build up the dp table based on a pattern
    for (int i = 2; i <= n; ++i) {
      // Even numbers have the same number of set bits as their previous even number divided by 2
      if (i % 2 == 0) {
        dp[i] = dp[i / 2];
      } else {
        // Odd numbers have 1 more set bit than their previous odd number
        dp[i] = dp[i - 1] + 1;
      }
    }

    return dp;
  }
};
