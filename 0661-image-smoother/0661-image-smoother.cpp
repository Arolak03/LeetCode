class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m =img.size();
        int n =img[0].size();
        // int row=0;
        // int col=0;
        if(m==1 && n==1)return img;
        
        vector<vector<int>> ans(m, vector<int>(n));
        if(m==1){
            for(int col=0;col<n;col++){
                //corner
                if(col==0)ans[0][col]=(img[0][col]+img[0][col+1])/2;
                else if(col==n-1)ans[0][col]=(img[0][col]+img[0][col-1])/2;
                else ans[0][col]=(img[0][col+1]+img[0][col]+img[0][col-1])/3;
            }
        }
        else if(n==1){
            for(int row=0;row<m;row++){
                //corner
                if(row==0)ans[row][0]=(img[row][0]+img[row+1][0])/2;
                else if(row==m-1)ans[row][0]=(img[row][0]+img[row-1][0])/2;
                else ans[row][0]=(img[row+1][0]+img[row][0]+img[row-1][0])/3;
            }
        }
        else {
            for(int row=0;row<m;row++){
            
                for(int col=0;col<n;col++){

                    if(row==0 && col==0)
                        ans[row][col]=(img[row+1][col]+img[row][col+1]+img[row+1][col+1]+img[row][col])/4;
                    else if(row==0 && col==n-1)
                        ans[row][col]=(img[row+1][col]+img[row][col-1]+img[row+1][col-1]+img[row][col])/4;
                    else if(row==m-1 && col==0)
                        ans[row][col]=(img[row-1][col]+img[row][col+1]+img[row-1][col+1]+img[row][col])/4;
                    else if(row==m-1 && col==n-1)
                        ans[row][col]=(img[row-1][col]+img[row][col-1]+img[row-1][col-1]+img[row][col])/4;
                    //edges
                    else if(row==m-1)
                        ans[row][col]=(img[row-1][col]+img[row-1][col-1]+img[row-1][col+1]+img[row][col-1]+img[row][col]+img[row][col+1])/6;
                    else if(row==0)
                        ans[row][col]=(img[row+1][col]+img[row+1][col-1]+img[row+1][col+1]+img[row][col-1]+img[row][col]+img[row][col+1])/6;
                    else if(col==n-1)
                        ans[row][col]=(img[row][col-1]+img[row+1][col-1]+img[row-1][col-1]+img[row][col]+img[row+1][col]+img[row-1][col])/6;
                    else if(col==0)
                        ans[row][col]=(img[row-1][col+1]+img[row][col+1]+img[row+1][col+1]+img[row-1][col]+img[row+1][col]+img[row][col])/6;
                    else ans[row][col]=(img[row-1][col]+img[row-1][col-1]+img[row-1][col+1]+img[row+1][col-1]+img[row+1][col]+img[row+1][col+1]+ img[row][col]+img[row][col+1]+img[row][col-1])/9;

                }
            }
        }
        return ans;
    }
};