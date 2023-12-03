class Solution {
public:
    
    void solve(vector<vector<int>>& mat,int& area){
        int m =mat.size();
        int n=mat[0].size();
        int i=0;
        int j=0;
    // vector<int> arr(n);
        while(i<m){
           vector<int> arr(n);
            for(j=0;j<n;j++){
                arr[j]=(mat[i][j]);
                // cout<<arr[i]<<" ";
                
            }
            vector<int> temp=arr;
            sort(arr.begin(),arr.end());
            for(int j=n-1;j>=0;j--){
                area=max(area,(n-j)*arr[j]);
                cout<<temp[n-j-1]<<" ";
                // if(arr[j]==0)break;
            }
            i++;
            arr=temp;
            if(i<m){
                for(int j=0;j<n;j++){
                    if(mat[i][j]!=0)mat[i][j]=arr[j]+1;
                    // cout<<mat[i][j]<<" ";
                }
            }
        }
    }
    
    
    int largestSubmatrix(vector<vector<int>>& mat) {
        int area=0;
        int m =mat.size();
        // for(int i=0;i<m;i++){
                //saare rows pr traverse krungi
        solve(mat,area);
        // }
        return area;
    }
};