class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        //bfs
        int n =mat.size();
        int m=mat[0].size();
        vector<pair<int,int>> s;
        vector<vector<int>> ans(n, vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    ans[i][j]=0;
                    s.push_back({i,j});
                }
            }
        }
        int i=0;
        int dirx[4]={-1,1,0,0};
        int diry[4]={0,0,-1,1};
        while(i<s.size()){
            int x=s[i].first;
            int y=s[i].second;
            i++;
            for(int i=0;i<4;i++){
                int nx=x+dirx[i];
                int ny=y+diry[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m && ans[nx][ny]==-1){
                    ans[nx][ny]=ans[x][y]+1;
                    s.push_back({nx,ny});
                }
            }
            
        }
        return ans;
    }
};