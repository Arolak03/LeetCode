class Solution {
public:
    int mul(int a, int b){
        return a*b;
    }
    
    // int tri(vector<int>& valuesint index){
//         if(n==0 || n==1 || n===2){
//             return 0;
//         }
//         if(n==3){
            
//             for(int i=0;i<3;i++){
//                 return mul(valyes[0], mul(values[1],values[2]));
//             }
//         }
//         int score = 1;
//         for(int i=0;i<values.size();i++){
//             for(int j=0;j<3;j++){
//                 score = score*()
                    
            
//             }
//         }
    // }
    
    // int solve(vector<int> &val, int i, int j,vector<vector<int>>& dp){
    //     int n = val.size();
    //     if(i+1==j){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int ans = INT_MAX;
    //     for(int k=i+1; k<j; k++){
    //         ans = min(ans, val[i]*val[j]*val[k]+solve(val,i,k,dp)+solve(val,k,j,dp));
    //         dp[i][j]=ans;
    //     }
    //     return dp[i][j];
    // }
     int solve(vector<int> &val){
         int n = val.size();
         vector<vector<int>> dp(n, vector<int>(n,0));
        // int n = val.size();
        // if(i+1==j){
        //     dp[i][j]=0;
        // }
        // if(dp[i][j]!=-1){
        //     return dp[i][j];
        // }
        for(int i=n-1;i>=0;i--){
            for(int j= i+2;j<n;j++){// i+2 to ensure atleast 3 vertices
        
        int ans = INT_MAX;
        for(int k=i+1; k<j; k++){
            ans = min(ans, val[i]*val[j]*val[k]+dp[i][k]+dp[k][j]);
           
        }
                 dp[i][j]=ans;
                      }}
        // return dp[i][j];
                      return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solve(values,0,n-1,dp);
        return solve(values);
    }
};