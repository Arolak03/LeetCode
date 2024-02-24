class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.length();
        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            if (!word.empty()) {
                st.push(word);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            ans += ' ';
            st.pop();
        }

        int j = ans.length();
        while (j >= 0 && ans[j - 1] == ' ') {
            j--;
        }

        return ans.substr(0, j);
    }
};
