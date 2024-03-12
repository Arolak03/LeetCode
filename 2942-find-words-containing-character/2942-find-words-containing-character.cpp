class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n =words.size();
        // int ans=0;
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            string word=words[i];
            for(int j=0;j<word.length();j++){
                if(word[j]==x){
                    ans.push_back(i);
                    break;
                }
            }
        }
    return ans;
    }
    
};