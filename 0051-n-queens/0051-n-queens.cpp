class Solution {
public:
    
    bool isSafe(int row,int col, vector<string>& board,int n){
        int r=row;
        int c=col;
        while(r>=0 && c>=0 ){
            if(board[r][c]=='Q'){
            // board[r][c]='Q';
            return false;
            }
            r--,c--;
        }
        r=row;
        c=col;
        //chrck row
        while(c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            c--;
            
        }
        //check lower diag
        r=row;
        c=col;
        while(r<n && c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r++;
            c--;
        }
        return true;
    }
    
    void solve(vector<vector<string>>& ans, vector<string>& op,int col, int n){
        if(col==n){
            ans.push_back(op);
            return ;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,op,n)){
                op[row][col]='Q';
                solve(ans,op,col+1,n);   
                op[row][col]='.';
    
            }
           
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> op(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            op[i]=s;
        }
        solve(ans,op,0,n);
        return ans;
    }
};



   