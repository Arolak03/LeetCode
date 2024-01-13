class Solution {
public:
    string frequencySort(string s) {
        int n =s.length();
        unordered_map<char, int>mpp;
        int count=0;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            count=max(count,mpp[s[i]]);
        }
        string ans="";
        while(count>0 && n--){
            for(auto it: mpp){
                if(it.second==count){
                    while(it.second--)
                        ans+=it.first;
                }
            }
            count--;
        }
        return ans;
        
    }
};