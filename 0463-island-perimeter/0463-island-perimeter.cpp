class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0){
            return 1;
        }
        if(grid[i][j]==-1){
            return 0;
        }
        grid[i][j]=-1;
        int perimeter=0;
        perimeter+=solve(grid,i-1,j);
        perimeter+=solve(grid,i+1,j);
        perimeter+=solve(grid,i,j-1);
        perimeter+=solve(grid,i,j+1);
        return perimeter;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n =grid[0].size();
        int perimeter=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    perimeter+=solve(grid,i,j);
                }
            }
        }
        return perimeter;
    }
};