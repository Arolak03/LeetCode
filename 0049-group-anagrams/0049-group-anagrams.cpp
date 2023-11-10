class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mpp;
        for(auto it: strs){
            string m = it;
            sort(m.begin(), m.end());
            mpp[m].push_back(it);
        }
        
        vector<vector<string>> ans;
        for(auto it: mpp){
            // for(auto itn: it.second)
            ans.push_back(it.second);
        }
        return ans;
    }
};