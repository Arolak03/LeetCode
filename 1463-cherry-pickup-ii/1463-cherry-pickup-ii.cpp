class Solution {
public:
    int solve(int r, int c, vector<vector<int>>& mat, int j1, int j2, int i, vector<vector<vector<int>>>& dp){
        if(j1<0 || j2<0 || i<0 || j1>=c || j2>=c || i>=r){
            return 0;
        }
        if(dp[j1][j2][i]!=-1)return dp[j1][j2][i];
        int inc=0;

        // int exc=0;
        for(int col1=-1;col1<=1;col1++){
            int nj1=j1+col1;
            for(int col2=-1;col2<=1;col2++){
                int nj2=j2+col2;
                if(nj1>=0 && nj2>=0 && nj1<c && nj2<c && i<r){
                    inc=max(inc,mat[i][nj1]+(nj1 != nj2 ? mat[i][nj2] : 0)+solve(r,c,mat,nj1,nj2,i+1,dp));
                }
            }
        }
        return dp[j1][j2][i]=inc;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(c+1, vector<vector<int>>(c+1, vector<int>(r+1,-1)));
        return solve(r,c,grid,0,c-1,1,dp)+grid[0][0]+grid[0][c-1];
    }
};