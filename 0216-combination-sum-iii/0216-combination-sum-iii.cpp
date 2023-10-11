class Solution {
public:
    
    void solve(int k,int index, int n,vector<int>& arr, vector<vector<int>>& ans, vector<int>& op){
        if(n==0 && k==0){
            ans.push_back(op);
            return; 
        }
        if(index>=arr.size() || k<0 || n<0)return;
        //include
        op.push_back(arr[index]);
        solve(k-1,index+1,n-arr[index],arr,ans,op);
        op.pop_back();
        solve(k,index+1,n,arr,ans,op);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> op;
        vector<int> arr;
        for(int i=1;i<=9;i++)arr.push_back(i);
        
        solve(k,0,n,arr,ans,op);
        return ans;
    }
};