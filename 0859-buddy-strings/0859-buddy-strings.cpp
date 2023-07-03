class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size() || s.size()==1)return false;
        vector<int>different;
        vector<int>ct(26,0);
        bool f=false;
        for(int i=0;i<s.size();i++){
            
            if(s[i]!=goal[i])different.push_back(i); //index rkha
            
            else{// if 2 same char in string s uski ascii value bhada rhi hu aur agr wo 2 y 2 s jyada h to swap krne pr bhi same hi aayega
                ct[s[i]-'a']++;
                if(ct[s[i]-'a']==2)f=true;
            }
        }
        
        if(different.size()>2)return false;
        if(different.size()==1)return false;
         if(different.size()==0){
             return f;
         }
        int in1,in2;
        in1 = different[0];
        in2 = different[1];
        swap(s[in1],s[in2]);
        return s==goal;
    }
};