class Solution {
public:
    void solve(vector<vector<int>> &grid, int index, int& count){
        if(index>=grid[0].size()){
            return;
        }
        int element=0;
        for(int i=0;i<grid.size();i++){
            element=max(element, grid[i][index]);
        }
        count+=element;
        solve(grid, index+1,count);
    }
    
    int deleteGreatestValue(vector<vector<int>>& grid) {
    
        for(int i=0;i<grid.size();i++){
            sort(grid[i].begin(), grid[i].end(), greater<int>());
            }
        
        int count=0;
        solve(grid, 0,count);
        return count;
    }
};