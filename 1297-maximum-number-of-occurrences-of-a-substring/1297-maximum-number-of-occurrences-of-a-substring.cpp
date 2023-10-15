class Solution {
public:
    bool valid(string s,int unique){
        // int count=0;
        // for(int i=0;i<s.length()-1;i++){
        //     if(s[i]!=s[i+1])count++;
        // }
        // if(count<=unique)return true;
        // return false;
        unordered_map<char, int> mpp;
        for(auto it: s){
            mpp[it]++;
        }
        if(mpp.size()>unique)return false;
        return true;
    }
    
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
       unordered_map<string, int> mpp;
        int maxi=0;
        if(maxSize==0 || s.length()==0)return 0;
        
        for(int i=0;i<s.length()-minSize+1;i++){
            string subs = s.substr(i,minSize);
            if(valid(subs,maxLetters)){
                mpp[subs]++;
                maxi=max(maxi,mpp[subs]);
            }
        }
        return maxi;
    }
};