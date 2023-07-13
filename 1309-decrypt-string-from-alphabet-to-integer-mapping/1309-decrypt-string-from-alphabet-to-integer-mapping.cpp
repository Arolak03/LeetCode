class Solution {
public:
    string freqAlphabets(string s) {
        string result = "";
        int n = s.length();
        int i = n - 1;
        
        while (i >= 0) {
            if (s[i] == '#') {
                int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                result = char('a' + num - 1) + result;
                i -= 3;
            } else {
                int num = s[i] - '0';
                result = char('a' + num - 1) + result;
                i--;
            }
        }
        
        return result;
    }
};
