class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count=0;
        int i=0;
        int n = s.length();
        while(i<n){
            while(s[i]=='('){
                st.push(s[i++]);
                cout<<i<<endl;
            }
            if(st.empty() && s[i]==')'){
                count++;
                i++;
            }
            if(s[i]==')' && !st.empty()){
                st.pop();
                i++;
            }
        }
        while(!st.empty()){
            st.pop();
            count++;
        }
           
           
        return count;
    }
};