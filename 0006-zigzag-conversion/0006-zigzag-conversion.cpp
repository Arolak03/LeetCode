class Solution {
public:
    string convert(string s, int numRows) {
        bool dir=true;
        int j=0;
        if(numRows==1)return s;
        vector<string> str(numRows, "");
        for(int i=0;i<s.length();i++){
            if(j==numRows-1 || j==0) dir=!dir;
            str[j]+=s[i];
            if(!dir)j++;
            else j--;
        }
        string ans="";
        for(auto it: str){
            ans+=it;
        }  
        return ans;
    }
};