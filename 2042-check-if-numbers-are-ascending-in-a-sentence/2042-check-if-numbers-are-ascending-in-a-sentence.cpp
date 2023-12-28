class Solution {
public:
    bool areNumbersAscending(string s) {
        int n =s.length();
        int prev=0;
        for(int i=0;i<n;i++){
            string temp="";
            if(s[i]>='1' && s[i]<='9'){
                while(i<n && s[i]!=' '){
                    temp+=s[i];
                    i++;
                }
                if(!temp.empty() && stoi(temp)<=prev)return false;
            }
            if(!temp.empty())prev=stoi(temp);
            
        }
        return true;
    }
};