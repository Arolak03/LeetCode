class Solution {
public:
    int solve(string& word1, string& word2, int index1, int index2, vector<vector<int>>& dp){
        if(index1==word1.length())return dp[index1][index2]=word2.length()-index2;
        if(index2==word2.length())return dp[index1][index2]=word1.length()-index1;
        if(index1>=word1.length() && index2>=word2.length())return 0;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(word1[index1]==word2[index2]){
            return dp[index1][index2]=0+solve(word1,word2,index1+1,index2+1,dp);
        }
        return 
            dp[index1][index2]=1+min(solve(word1,word2,index1+1,index2,dp),solve(word1,word2,index1,index2+1,dp));
    }
    
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1,-1));
        return solve(word1, word2,0,0,dp);
    }
};