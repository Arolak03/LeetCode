class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n =coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1));
        //if amount is 0 retuirn 1
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        //iamount
        for(int index=n-1;index>=0;index--){
            for(int j=1;j<=amount;j++){
                if(coins[index]>j){
                    dp[index][j]=dp[index+1][j];
                }
                
                else {dp[index][j]=dp[index][j-coins[index]]+dp[index+1][j];}
            }
        }
        return dp[0][amount];
    }
};