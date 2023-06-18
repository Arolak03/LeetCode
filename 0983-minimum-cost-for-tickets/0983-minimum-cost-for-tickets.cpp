class Solution {
public:
    
    int cost(int n,vector<int>& days, vector<int> &costs, int index){
        vector<int> dp(n+1,-1);
        // int n = days.size();
        dp[n]=0;
        for(int k=n-1;k>=0;k--){
            int option1=costs[0]+dp[k+1];
        // int option2;
        // int option3;
        int i;
        for(i=k; i<n && days[i] < days[k]+7 ;i++);
        int option2=costs[1]+dp[i];
        
        // int j;
        for(i=k; i<n && days[i] < days[k]+30 ;i++);
        int option3=costs[2]+dp[i];
        
        dp[k]=min(option1,min(option2,option3));
            
        }
        return dp[0];
        
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // vector<int> dp(n+1, -1);
        return cost(n,days,costs,0);
    }
};