class Solution {
public:
    int slice(vector<int>& slices,int end,int ind, int n, vector<vector<int>>& dp){
        // int n = slices.size();
        // n is what i can eat
        if(ind>end || n==0){
            return 0;
        }
        if(dp[ind][n]!=-1){
            return dp[ind][n];
        }
        // int eat;
        // itn not eat;
        // int sum =0;
        // for(int i=0;i<n;i++){
        //     if (i!=0){
        //         //eat
        //         eat=max(sum,slices[ind]+slice(slices,ind+1,dp));
        //         sum=eat;
        //     }
        //     else{
        //         eat = max(sum,slices[ind]+slice(slices,ind+1,dp));
        //         sum = eat;
        //     }
        // }
        
        
        int eat = slices[ind]+slice(slices,end,ind+2,n-1,dp);
        int noteat= 0 + slice(slices,end,ind+1,n,dp);
        return dp[ind][n] = max(eat, noteat);
        
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp1(n,vector<int>(n,-1));
         vector<vector<int>> dp2(n,vector<int>(n,-1));
        int case1 = slice(slices,n-2,0,n/3,dp1);
        int case2 = slice(slices,n-1,1,n/3,dp2);
        return max(case1, case2);
    }
};