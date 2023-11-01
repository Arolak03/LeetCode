class Solution {
public:
    int n;
    int m;
    bool solve(vector<vector<char>>& board, string word, int i, int j, int index){
        if(index==word.length())return true;
        if(i>=n || j>=m || i<0 || j<0 )return false;
        if(board[i][j]!=word[index])return false;
        // if mil jaaye then markm vis
        char temp=board[i][j];
        board[i][j]='$';
        //left right up down
        if(solve(board,word,i-1,j,index+1) ||
           solve(board,word,i+1,j,index+1) ||
           solve(board,word,i,j+1,index+1) ||
           solve(board,word,i,j-1,index+1)){
            return true;
        }
        //backtrack
        board[i][j]=temp;
        return false;
    }
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
       n =board.size();
        m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && solve(board,word,i,j,0))return true;
            }
        }
        return false;
    }
};