class Solution {
private:
    
    void solve(string digits, vector<string>& ans,string& temp, vector<string>& pad, int index){
        // vector<string> output;
        if(index==digits.size()){
            ans.push_back(temp);
            return;
        }
        //phle process
        string value=pad[digits[index]-'0'];
        for(int i=0;i<value.size();i++){
        temp.push_back(value[i]);
        // ans.push_back(output);
        solve(digits,ans,temp,pad,index+1);
        temp.pop_back();
        }

    }
    
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string temp;
        vector<string> ans;
    
        vector<string> pad = {"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,temp,pad, 0);
        return ans;
    }
};