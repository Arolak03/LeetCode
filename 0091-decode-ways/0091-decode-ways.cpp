class Solution {
public:
    int solve(string& s, int index,vector<int>& dp){
        if(index>=s.length())return 1;
        if(dp[index]!=-1)return dp[index];
        int count=0;
        
        if(s[index]!='0')count+=solve(s,index+1,dp);
        if(index+1<s.length() && (s[index]=='1' || s[index]=='2' && s[index+1]<'7')){
            count+=solve(s,index+2,dp);
            // return count;
        }
        return dp[index]=count;
    }
    
    
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
        return s.length()!=0? solve(s,0,dp) : 0;
    }
    
    
};