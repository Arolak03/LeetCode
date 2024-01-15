class Solution {
public:
    int ans=0;
    bool isPalindrome(string s){
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        // cout<<"yes";
        return  true;
    }
    void solve(string& s,string& s1, string& s2, int index){
        if(index>=s.length()){
            if(isPalindrome(s1) && isPalindrome(s2))
            ans=max(ans,(int)(s1.length()*s2.length()));
            return;
        }
        // if(isPalindrome(s1+s[index])){
            s1.push_back(s[index]);
            solve(s,s1,s2,index+1);
            s1.pop_back();
        // }
        // if(isPalindrome(s2+s[index])){
            s2.push_back(s[index]);
            solve(s,s1,s2,index+1);
            s2.pop_back();
        // }
        solve(s,s1,s2,index+1);
    }
    
    int maxProduct(string s) {
        // int ans=0;
        string s1="";
        string s2="";
        solve(s,s1,s2,0);
        return ans;
    }
};