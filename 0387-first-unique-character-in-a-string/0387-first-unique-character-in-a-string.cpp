class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mpp;
        for(int i=0;i<s.length();i++){
            // char c=s[i];
            mpp[s[i]]++;
            // if(s.count(c)>1)return i;
        }
        for(int i=0;i<s.length();i++){
            if(mpp[s[i]]==1)return i;
        }
        return -1;
    }
};