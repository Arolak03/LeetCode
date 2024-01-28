class Solution {
public:

    // int solve(int sum, vector<vector<int>>& mat, int k, int row, int col){
    //     if(sum==k)return 1;
    //     if(row<0 || col<0 || row>=mat.size() || col>=mat[0].size())return 0;
    //     //baktrack
    //     int right=solve(sum+mat[row][col+1],mat,k,row,col+1);
    //     int down=solve(sum+mat[row+1][col],mat,k,row+1,col);
    //     int rightd=solve(sum+mat[row+1][col+1]+mat[row][col+1]+mat[row+1][col],mat,k,row+1,col+1);
    //     return right+down+rightd;
    // }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }

        for(int c1=0;c1<matrix[0].size();c1++){
            for(int c2=c1;c2<matrix[0].size();c2++){
                int sum=0;
                unordered_map<int, int> mpp;
                mpp[0]=1;
                for(int row=0;row<matrix.size();row++){
                    sum+=matrix[row][c2]-(c1>0? matrix[row][c1-1]: 0);
                    ans+=mpp[sum-target];
                    mpp[sum]++;
                }
            }
        }
        return ans;
    }
};