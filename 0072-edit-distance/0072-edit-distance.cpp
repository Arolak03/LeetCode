class Solution {
public:
    int solve(string word1, string word2, int i, int j, vector<vector<int>>& dp){
        if(i>=word1.length()){
            return word2.length()-j;
            //insert a chota
        }
        if(j>=word2.length()){
            return word1.length()-i;
            //delete b chota
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        //same
        
        if(word1[i]==word2[j]){
            ans = solve(word1, word2, i+1, j+1,dp);
        } //not same replace insert delete
        else{
            //replace
            
            int insert = 1+solve(word1,word2,i,j+1,dp);
            int replace = 1+solve(word1, word2, i+1,j+1,dp);
            int del = 1+solve(word1,word2,i+1,j,dp);
            //insert
            ans = min(insert,min(del,replace));
        }
        return dp[i][j]=ans;
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp (word1.length(), vector<int>(word2.length(),-1));
        return solve(word1, word2, 0,0,dp);
    }
};