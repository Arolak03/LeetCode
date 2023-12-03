class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        vector<pair<int, int>> prev;
        
        for(int row=0;row<m;row++){
            vector<pair<int, int>>heights;
            vector<bool> seen=vector(n,false);
            for(auto [height, col]: prev){
                if(mat[row][col]==1){
                    heights.push_back({height+1,col});
                    seen[col]=true;
                }
            }
            for(int col=0;col<n;col++){
                if(seen[col]==false && mat[row][col]==1){
                    heights.push_back({1,col});
                }
            }
            for(int j=0;j<heights.size();j++){
                ans=max(ans, (j+1)*heights[j].first);
            }
            prev=heights;
        }
        
        return ans;
    }
};