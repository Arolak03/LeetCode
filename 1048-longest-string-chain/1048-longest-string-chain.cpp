class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n==1)return 1;
        sort(words.begin(), words.end(), [&] (string& a, string& b){
            return a.size()<b.size();
        });
             
        //vector jiske index uske number of letters k hoga 
        vector<unordered_map<string, int>>mpp(17);
        for(auto w: words){
            mpp[w.size()][w]=1;
        } 
        int ans=0;
        for(auto w: words){
            int sz=w.size();
            if(sz==1)continue;
            for(int i=0;i<sz;i++){
                string m = w.substr(0,i)+w.substr(i+1);
                if(mpp[sz-1].count(m)){
                    mpp[sz][w]=max(mpp[sz][w], 1+mpp[sz-1][m]);
                }
            }
            ans=max(ans,mpp[sz][w]);
        }
        return ans;
        
    }
};