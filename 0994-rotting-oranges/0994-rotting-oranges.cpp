class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt=0, tot=0;
        int x=grid.size(), y=grid[0].size(), time=0;
        queue<pair<int, int>>rotten;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(grid[i][j]!=0)tot+=1;
                if(grid[i][j]==2){
                    // tot+=1;
                    rotten.push({i,j});
                }
            }
        }
        //rotten queue m h ab
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!rotten.empty()){
            
            //x and y coordinates;
            // rotten.pop();
            int k=rotten.size();
            cnt+=k;
            while(k--){
                int m=rotten.front().first;
                int n=rotten.front().second;
                rotten.pop();
                for(int i=0;i<4;i++){
                    int mx=m+dx[i];
                    int my=n+dy[i];
                    
                    if(mx<0 || my<0 || mx>=x || my>=y || grid[mx][my]!=1)continue;
                    grid[mx][my]=2;
                    rotten.push({mx,my});
                }
            }
            if(!rotten.empty())time++;
        }
              
        for(int i =0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                return -1;
            }
        }
        return time;
              
        
    }
};