class Solution {
public:
    
    bool solve(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        //a end hpjaye and not b 
        if(i<0 && j<0){
            return true;;
        }
        
        if(i>=0 && j<0){
            return false;
        }
        
        if(i<0  && j>=0){
            //pattern not and string khtm
            for(int k=0;k<=j;k++){
                if(b[k] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(a[i]==b[j] || b[j]=='?'){
            return dp[i][j]=solve(a,b,i-1,j-1,dp);
        }
        // ? aajaye
        // else if(b[j]=='?'){
        //     return solve(a,b,i-1,j-1);
        // }
        else if(b[j]=='*'){
            //ya to ek hi change hua
            return dp[i][j] =(solve(a,b,i,j-1,dp) || solve(a,b,i-1,j,dp));
        }
        else{
            return false;
        }
        
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(), vector<int>(p.length(),-1));
        return solve(s,p,s.length()-1,p.length()-1,dp);
    }
};