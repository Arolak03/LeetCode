class Solution {
public:
    bool halvesAreAlike(string s) {
        int n =s.length();
        int count1=0;
        int count2=0;
        for(int i=0;i<n/2;i++){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i' || s[i]=='o' || s[i]=='u' ||
              s[i]=='A' || s[i]=='E'|| s[i]=='I' || s[i]=='O' || s[i]=='U'){
                count1++;
            }
            if(s[n/2+i]=='a' || s[n/2+i]=='e'|| s[n/2+i]=='i' || s[n/2+i]=='o' || s[n/2+i]=='u' ||
               s[n/2+i]=='A' || s[n/2+i]=='E'|| s[n/2+i]=='I' || s[n/2+i]=='O' || s[n/2+i]=='U'){
                count2++;
            }
        }
        return count1==count2;
    }
};