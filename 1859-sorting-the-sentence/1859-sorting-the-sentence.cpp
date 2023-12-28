class Solution {
public:
    string sortSentence(string s) {
        vector<string> mpp(10);
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            int temp=i;
             if ('0' <= s[i] && s[i] <= '9') {
                while (temp >= 0 && '0' <= s[temp] && s[temp] <= '9') {
                    temp--;
                }
                int place=stoi(s.substr(temp+1,i-temp));
                // cout<<(s.substr(temp+1,i-temp))<<" ";
                 string word="";
                 
                while(temp>=0 && s[temp]!=' '){
                    
                    word+=s[temp];
                    temp--;
                }
                
                reverse(word.begin(), word.end());
                 // cout<<word;
                mpp[place]=word;
            }
        }
        // for(auto it: mpp)cout<<it<<" ";
        string ans = "";
        for (int i = 0; i < mpp.size(); i++) {
            ans += mpp[i];
            if (i < mpp.size() - 1 && !mpp[i+1].empty()) {
                ans += ' ';
            }
        }
        string temp="";
        for(int i=1;i<ans.length();i++){
            temp+=ans[i];
        }
        return temp;
    }
};