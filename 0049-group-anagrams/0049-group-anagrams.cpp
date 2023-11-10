class Solution {
public:
    
    map<char,int> solve(string s){
        map<char,int>mp; 
        for(char c: s){
            mp[c]++;
        }
        return mp;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>, vector<string>> mpp;
        //O(n*length of each word)
        for(auto it: strs){
            mpp[solve(it)].push_back(it);
        }
        
        vector<vector<string>> ans;
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};




// map<char, int> helper(string s){
//   map<char, int> mp;
//   for(char ch: s){
// 	mp[ch]++;
//   }
//   return mp;
// }
// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//   map<map<char, int>, vector<string>> mp;
//   vector<vector<string>> ans;
//   for(string s: strs){
// 	mp[helper(s)].push_back(s);
//   }
//   for(auto p: mp){
// 	ans.push_back(p.second);
//   }
//   return ans;
// }