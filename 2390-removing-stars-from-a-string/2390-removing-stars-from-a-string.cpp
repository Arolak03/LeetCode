class Solution {
public:
    string removeStars(string s) {
        int n =s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            while(i<n && s[i]!='*'){
                st.push(s[i]);
                i++;
            }
            while(i<n && s[i]=='*' && !st.empty()){
                
                st.pop();
                i++;
            }
            i--;
        }
        if(st.size()==n)return s;
        string ans="";
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};