class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mpp;
        int n =s.length();
        for(int i=0;i<=n-10;i++){
            string temp=s.substr(i,10);
            mpp[temp]++;        
        }
        vector<string> ans;
        for(auto it: mpp){
            if(it.second>1)ans.push_back(it.first);
        }
        return ans;
    }
};