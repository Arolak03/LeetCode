class Solution {
public:
    
    void solve(int k,int i, int n, vector<vector<int>>& ans, vector<int>& op){
        if(n==0 && k==0){
            ans.push_back(op);
            return; 
        }
        if(i>9 || k<0 || n<0)return;
        //include
        // for(int i=1;i<=9;i++){
            op.push_back(i);
            solve(k-1,i+1,n-i,ans,op);
            op.pop_back();
            solve(k,i+1,n,ans,op);
        // }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> op;
        // vector<int> arr;
        // for(int i=1;i<=9;i++)arr.push_back(i);
        
        solve(k,1,n,ans,op);
        return ans;
    }
};