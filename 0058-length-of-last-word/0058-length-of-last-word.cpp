class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int count=0;
        for(int i=n-1;i>=0;i--){
            if(i==n-1  && s[i]==' ')
                while(s[i]==' ') i--;
            
            if(s[i]==' ')return count;
            count++;
        }
        return count;
    }
};