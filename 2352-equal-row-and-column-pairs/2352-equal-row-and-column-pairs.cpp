class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<vector<int>> row, col;
        for(int i=0;i<n;i++){
            row.push_back(grid[i]);
        }
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            col.push_back(temp);
        }
        
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(row[i]==col[j])ans++;
            }
        }
        return ans;
    }
};