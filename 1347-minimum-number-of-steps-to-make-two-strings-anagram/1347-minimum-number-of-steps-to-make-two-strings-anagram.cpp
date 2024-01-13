class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int>  mpp1,mpp2;
        for(int i=0;i<s.length();i++){
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }
        int count=0;
        
        
            
        for(int i=0;i<s.length();i++){
            if(mpp2[s[i]]!=0 && mpp2.find(s[i])!=mpp2.end()){
                mpp2[s[i]]--;
            }
        }
        for(auto it: mpp2)count+=it.second;
        return count;
    }
};