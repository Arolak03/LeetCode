#define MOD 1000000007;
class Solution {
public:
    int countHomogenous(string s) {
        int cnt=1;
        int ans=s.length();
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                ans=(ans+cnt)%MOD;
                cnt++;
            }
            else{
                cnt=1;
            }
        }
        return ans;
    }
};