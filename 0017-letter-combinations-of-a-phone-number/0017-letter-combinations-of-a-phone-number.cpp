class Solution {
public:
    
    
    void solve(string digit, vector<string>& test, vector<string>& ans, string& op, int index){
        if(index==digit.length()){
            ans.push_back(op);
            return;
        }
        int ind=digit[index]-'0';
        string ww=test[ind];
        for(char c: ww){
            // op+=ww[i];
            op.push_back(c);
            solve(digit,test,ans,op,index+1);
            op.pop_back();
            // solve(digit,test,ans,op,index);
        }
        
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string> test={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string op = "";
        solve(digits,test,ans,op, 0);
        return ans;
        
    }
};