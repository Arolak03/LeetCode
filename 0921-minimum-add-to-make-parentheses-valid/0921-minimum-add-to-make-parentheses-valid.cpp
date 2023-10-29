class Solution {
public:
    int minAddToMakeValid(string s) {
        int n =s.length();
        int ans=0;
        int reqd=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                reqd++;
            }
            else{
                reqd--;
            }if(reqd==-1){
                ans++;
                reqd++;
            }
        }
        return ans+reqd;
    }
};