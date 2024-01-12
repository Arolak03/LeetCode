class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        sort(words.begin(), words.end());
        int count=0;
        vector<string> ans;
        int n =words.size();
//         for(int i=0;i<n;i++){
//             int j=i;
//             while(j<n && words[i]==words[j]){
//                 j++;
//             }
//             if(count<j-i){
//                 while(!ans.empty()){
//                     ans.pop_back();
//                 }
//                 count=j-1;
//                 ans.push_back(words[i]);
//             }
            
//             else if(count==j-i){
//                 ans.push_back(words[i]);
//             }
//         }
//         return ans;
        map<string, int> mpp;
        for(int i=0;i<n;i++){
            mpp[words[i]]++;
        }
        for(auto it: mpp){
            if(it.second>count){
                count=it.second;
            }
        }
        
        int index=0;
        while(k>0){
            for(auto it: mpp){
                if(it.second==count && k>0){
                    ans.push_back(it.first);
                    index++;
                    k--;
                }
            }
            if(ans.size()>2)sort(ans.begin()+index-1,ans.end());
            count--;
        }
        
        return ans;
    }
};