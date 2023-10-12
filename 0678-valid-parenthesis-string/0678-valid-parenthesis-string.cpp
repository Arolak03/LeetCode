#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        if (n == 0) return true;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') dp[i][i] = true;
            if (i < n - 1 && 
                (s[i] == '(' || s[i] == '*') && 
                (s[i + 1] == ')' || s[i + 1] == '*')) {
                dp[i][i + 1] = true;
            }
        }

        for (int size = 2; size < n; size++) {
            for (int i = 0; i + size < n; i++) {
                if (s[i] == '*' && dp[i + 1][i + size]) {
                    dp[i][i + size] = true;
                } else if (s[i] == '(' || s[i] == '*') {
                    for (int k = i + 1; k <= i + size; k++) {
                        if ((s[k] == ')' || s[k] == '*') &&
                            (k == i + 1 || dp[i + 1][k - 1]) &&
                            (k == i + size || dp[k + 1][i + size])) {
                            dp[i][i + size] = true;
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
