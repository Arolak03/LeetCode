// #define MOD = 1000000007;
class Solution {
public:
    
    int trips(vector<int>& locations, int start, int end, int currCity, int fuel, vector<vector<int>>& dp){
        int MOD = 1000000007;
        if(fuel<0){
            return 0;
        }
        int ans = 0;
        if(currCity == end){
            ans= 1;
        }
        if(dp[currCity][fuel]!=-1){
            return dp[currCity][fuel];
        }
        
        for(int nextCity=0;nextCity<locations.size();nextCity++){
            if(nextCity != currCity && fuel >= abs(locations[currCity]- locations[nextCity])){
                ans = (ans%MOD +trips(locations,start,end,nextCity,fuel - abs(locations[currCity]-locations[nextCity]),dp)%MOD)%MOD;
            }
        }
        return dp[currCity][fuel] = ans;
        
    }
    
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n =locations.size();
        vector<vector<int>> dp(n+1, vector<int>(fuel+1,-1));
        return trips(locations,start, finish, start, fuel,dp);
    }
};