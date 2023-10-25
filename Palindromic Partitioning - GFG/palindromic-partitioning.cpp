//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int palindromicPartition(string s) {
    int n = s.length();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    vector<int> dp(n, INT_MAX);

    for (int end = 0; end < n; end++) {
        for (int start = 0; start <= end; start++) {
            if (s[start] == s[end] && (end - start <= 1 || isPalindrome[start + 1][end - 1])) {
                isPalindrome[start][end] = true;
            }
        }
    }

    for (int end = 0; end < n; end++) {
        for (int start = 0; start <= end; start++) {
            if (isPalindrome[start][end]) {
                dp[end] = (start == 0) ? 0 : min(dp[end], dp[start - 1] + 1);
            }
        }
    }

    return dp[n - 1];
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends