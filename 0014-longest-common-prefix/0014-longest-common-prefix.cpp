class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans="";
        string f=strs[0];
        int n =strs.size();
        string last=strs[n-1];
        for(int i=0;i<min(f.size(), last.size());i++){
            if(f[i]!=last[i])return ans;
            ans+=f[i];
        }
        // unordered_map<string, int> mpp;
        // string word;
        return ans;
    }
};
