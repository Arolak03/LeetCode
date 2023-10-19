class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> s11;
        vector<string> s22;
        for(int i=0;i<s1.length();i++){
            string s="";
            while(s1[i]!=' ' && i<s1.length())s+=s1[i++];
            s11.push_back(s);
        }
        for(int i=0;i<s2.length();i++){
            string s="";
            while(s2[i]!=' ' && i<s2.length())s+=s2[i++];
            s22.push_back(s);
        }

        unordered_map<string, int> mpp;
        vector<string> ans;
        for(int i=0;i<s11.size();i++)mpp[s11[i]]++;
        for(int i=0;i<s22.size();i++)mpp[s22[i]]++;
        for(auto it: mpp){
            if(it.second==1)ans.push_back(it.first);
            
        }
        return ans;
    }
};