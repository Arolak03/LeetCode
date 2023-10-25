//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isPalindrome(string s, int start, int end,vector<vector<int>>& check){
       if(start>=end)return true;
       if(check[start][end]!=-1)return check[start][end];
    
        if(s[start]==s[end] && isPalindrome(s,start+1,end-1,check)){
            check[start][end]=1;
            return true;
        }
        check[start][end]=0;
        return false;
        
    }

    int solve(string s, int prev, int index,vector<vector<int>>& dp,vector<vector<int>>& check){
        if(prev>=index || isPalindrome(s,prev,index,check))return 0;
        if(dp[prev][index]!=-1)return dp[prev][index];
        int ans=INT_MAX;
        int count;
        // for(int index=n-1;index>=1;index--){
        //     for(int prev=1;prev<=n;prev++){
                for(int i=prev;i<index;i++){
                    if(!isPalindrome(s,prev,i,check)){
                        continue;
                    }
                    count =solve(s,i+1,index,dp,check)+1;
                    ans=min(count,ans);
                }
            // }
        // }
        
        return dp[prev][index]=ans;
    }

    int palindromicPartition(string str)
    {
        int n = str.length();
        vector<vector<int>> dp(str.length()+1,vector<int>(str.length()+1,-1));
        vector<vector<int>> check(n+1, vector<int>(n+1,-1));
        // code here
        return solve(str,0,str.length()-1,dp,check);
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