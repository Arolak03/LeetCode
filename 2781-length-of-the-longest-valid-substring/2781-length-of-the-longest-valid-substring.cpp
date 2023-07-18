class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        
        int len = 0;
        unordered_set<string> st;
        for(auto s: forbidden){
            st.insert(s);
            len = max(len,int(s.size()));
        }
        int l=0;
        int r=0;
        int ans= 0;
        int n = word.size();
        //jo max len hoga
        while(r<n){
            
            string temp;
            //jo i hoga wo r to l bhaagega
            for(int i=r;(i>=l) && (i>r-len);i--){
                temp =word[i]+temp;
                if(st.count(temp)){
                    l=i+1;
                    break;
                }
            }
            r++;
            ans=max(ans,r-l);
        }
        return ans;
        
    }
};