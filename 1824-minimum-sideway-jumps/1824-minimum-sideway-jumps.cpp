class Solution {
public:
    int jumps(vector<int>& obs, int pos, int lane,vector<vector<int>>& dp){
        int n = obs.size()-1;
        if(pos==n){
            return 0;
        }
        if(dp[lane][pos]!=-1){
            return dp[lane][pos];
        }
        
        if(obs[pos+1]!=lane){
            return jumps(obs,pos+1,lane,dp);
            }
        else{
            int ans = INT_MAX;
            for(int i = 1;i<=3;i++){ // jispr koodna h
                if(obs[pos]!=i && lane!=i){
                    ans = min(ans, 1+jumps(obs,pos,i,dp));
                }    
            }
            dp[lane][pos]=ans;
            return dp[lane][pos];
                
                
            }     
    }
    int minSideJumps(vector<int>& obstacles) {
        int n =obstacles.size();
        vector<vector<int>> dp(4,vector<int>(n,-1)); //pos and lane change
        return jumps(obstacles,0,2,dp);
        
        
    }
};