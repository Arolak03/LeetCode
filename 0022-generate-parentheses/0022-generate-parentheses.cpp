class Solution {
public:
    
    
    
    void solve(int n ,string s, vector<string>& ans, int left, int right){
        if(n==0 && left==right){
            ans.push_back(s);
            return;
        }
        if(n==0 || left<right)return;
        if(!s.empty() && left>=right){
            solve(n-1,s+'(',ans,left+1,right);
            solve(n-1,s+')',ans,left,right+1);
        }
        else{
            solve(n-1,s+'(',ans,left+1,right);
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(2*n, "" ,ans,0,0);
        return ans;
    }
};