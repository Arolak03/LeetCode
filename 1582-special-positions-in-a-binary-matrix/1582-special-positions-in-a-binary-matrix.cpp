class Solution {
public:
    
    bool check(int row, int col, vector<vector<int>>& mat){
        int m=mat.size();
        int n=mat[0].size();
        for(int k=0;k<n;k++){
            if(mat[row][k]==1 && k!=col)return false;
                    }
        for(int k=0;k<m;k++){
            if(mat[k][col]==1 && k!=row)return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int m =mat.size();
        int n =mat[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    int row=i;
                    int col=j;
                    // cout<<row<<" "<<col<<" ";
                    if(check(row,col,mat))count++;
                }
            }
        }
        return count;
    }
};