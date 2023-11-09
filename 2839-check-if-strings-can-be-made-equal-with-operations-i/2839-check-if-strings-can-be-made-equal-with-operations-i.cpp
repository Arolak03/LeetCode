class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n =s1.length();
        for(int i=0;i<n-2;i++){
            if(s1[i]!=s2[i]){
                int j=i+2;
                cout<<1;
                swap(s1[i],s1[j]);
            }
            else continue;
        }
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i])return false;
        }
        return true;
    }
};