class Solution {
public:
    char repeatedCharacter(string s) {
        char c='\0';
        vector<int> letter(26,0);
        for(int i=0;i<s.length();i++){
            letter[s[i]-'a']++  ;
            if(letter[s[i]-'a']==2){
                c=s[i];
                break;
            }
        }
        return c;
    }
};