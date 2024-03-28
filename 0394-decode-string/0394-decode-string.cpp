class Solution {
public:
    
    bool isNum(char c){
        if(c >= '0' && c <= '9') return true;
        return false;
    }

    bool isAlpha(char c){
        if(c >= 'a' && c <= 'z') return true;
        return false;
    }

    string decodeString(string s) {
        stack<int> num;
        stack<string> chars;
        string res = "";
        int n = 0;
        for(int i=0;i<s.size();i++){
            if(isNum(s[i])) {
                n = n*10+(s[i]-'0'); // for eg : s = 100[leet]
            }
            else if(isAlpha(s[i])){
                res += s[i];
            }
            else if(s[i] == '['){
                chars.push(res);
                num.push(n);
                res = "";
                n = 0;
            }
            else if(s[i] == ']'){
                int nPrev = num.top();
                num.pop();
                string strPrev = chars.top();
                chars.pop();
                while(nPrev--){
                    strPrev += res;
                }
                res = strPrev;
            }
        }
        return res;
    }
};