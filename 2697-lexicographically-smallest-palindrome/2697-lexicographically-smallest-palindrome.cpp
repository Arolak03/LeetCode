class Solution {
public:
    string makeSmallestPalindrome(string s) {
        string r = s;
        int n = s.length();
        reverse(r.begin(), r.end());
        int i=0;
        while(i<n){
            if(s[i]!=r[i] && s[i]>r[i]){
                s[i]=r[i];
                r[n-i-1]=r[i];
                i++;
            }
            else if(s[i]==r[i] && s[i]<r[i]){
                s[n-1-i]=s[i];
                r[i]=s[i];
                i++;
            }
            else if(s[i]==r[i]){
                i++;
            }else{
                i++;
            }
        }
        return s;
    }
};