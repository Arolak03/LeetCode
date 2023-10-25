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
        // if(prev>=index || isPalindrome(s,prev,index,check))return 0;
        // if(dp[prev][index]!=-1)return dp[prev][index];
        // int ans=INT_MAX;
        // int count;
      
        //         for(int i=prev;i<index;i++){
        //             if(!isPalindrome(s,prev,i,check)){
        //                 continue;
        //             }
        //             count =solve(s,i+1,index,dp,check)+1;
        //             ans=min(count,ans);
        //         }
          
        // return dp[prev][index]=ans;
    }
        bool isPalindrome1(string s, int i, int j){
            // string str=s;
            // reverse(s.begin(),s.end());
            while(i<j){
                if(s[i]!=s[j])return false;
                i++;
                j--;
            }
            return true;
        }
        int solve1(string& s,int index, vector<int>& dp){
            int n = s.length();
            
            if(index==n)return 0;
            if(dp[index]!=-1)return dp[index];
            
            // string temp="";
            int minCost=INT_MAX;
            
            for(int j=index;j<n;j++){
                // temp+=s[j];
                if(isPalindrome1(s,index,j)){
                    int cost=1+solve1(s,j+1,dp);
                    minCost=min(cost,minCost);
                }
            }
            return dp[index]=minCost;
        }
    

    int palindromicPartition(string str)
    {
        int n = str.length();
        // vector<vector<int>> dp(str.length()+1,vector<int>(str.length()+1,-1));
        // vector<vector<int>> check(n+1, vector<int>(n+1,-1));
        // return solve(str,0,str.length()-1,dp,check);
        
        vector<int>dp(n+1,-1);
        return solve1(str,0,dp)-1;
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