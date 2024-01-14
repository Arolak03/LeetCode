class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n =word1.length();
        int m =word2.length();
        if(n!=m)return false;
        // int count1=0;
        // int count2=0;
        vector<int> mpp1(26),mpp2(26);
        for(int i=0;i<n;i++){
            mpp1[word1[i]-'a']++;
        //     count1=max(count1,mpp1[word1[i]]);
            mpp2[word2[i]-'a']++;
        //     count2=max(mpp2[word2[i]],count2);
        }
        for(int i=0;i<26;i++){
            if((mpp1[i]!=0 && mpp2[i]==0) || (mpp1[i]==0 && mpp2[i]!=0))return false;
        }
        sort(mpp1.begin(),mpp1.end());
        sort(mpp2.begin(),mpp2.end());
        for(int i=0;i<26;i++){
            if(mpp1[i]!=mpp2[i])return false;
        }
        
        // if(count1!=count2)return false;
        // for(auto it: mpp1){
        //     char temp=it.first;
        //     if(mpp2.find(temp)==mpp2.end())return false;
        // }
        
        return true;
    }
};