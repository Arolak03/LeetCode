class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int index1 = 0;
        int index2=0;
        int count =0;
        string ans="";
        while(index1<word1.length() && index2<word2.length()){
            if(count%2==0){
                ans = ans+word1[index1++];
                count++;
;           }
            else{
                ans = ans+word2[index2++];
                count++;
            }
        }
        while(index1<word1.length()){
            ans = ans+word1[index1++];
        }
        while(index2<word2.length()){
            ans=ans+word2[index2++];
        }
        return ans;
              
    }
};