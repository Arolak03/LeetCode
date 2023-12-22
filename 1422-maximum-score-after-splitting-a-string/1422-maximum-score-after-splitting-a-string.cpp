class Solution {
public:
    int maxScore(string s) {
        // string left=s.substr(s.begin(),s.length()-1);
        // string right=s.substr(s.begin()+s.length()-1,1);
        int lefts=0;
        if(s[0]=='0')lefts=1;
        int rights=0;
        for(int i=1;i<s.length();i++)if(s[i]=='1')rights++;
        
        int count=0;
        count=lefts+rights;
        for(int i=1;i<s.length()-1;i++){
            if(s[i]=='0')lefts++;
            else if(s[i]=='1')rights--;
            count=max(count, lefts+rights);
        }
        return count;
    }
};