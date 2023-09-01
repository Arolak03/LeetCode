class Solution {
public:
    
    void dfs(int sum, vector<int>& ans, int n){
        if(sum>=n){
            return;
        }
        for(int i=0;i<=9;i++){
            if(sum*10+i <= n){
                ans.push_back(sum*10 + i);
                dfs(sum*10 + i,ans,n);
            }
            
        }
    }
    
    vector<int> lexicalOrder(int n) {
        int sum =0;
        vector<int> ans;
        // 1 s start hone wale sare
        for(int i=1;i<=9;i++){
            if(sum*10+i<=n){
                ans.push_back(sum*10+i);
                dfs(sum*10+i,ans,n);
            }
        }
        return ans;
        
    }
};