class Solution {
public:
    string reverseWords(string s) {
        int spaceind = -1;
        int n = s.length();
        
        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == ' ') { // y to end ya to space
                int startIndex = spaceind + 1;
                int endIndex = i - 1;
                while (startIndex < endIndex) {
                    char temp = s[startIndex];
                    s[startIndex] = s[endIndex];
                    s[endIndex] = temp;
                    startIndex++;
                    endIndex--;
                }
                spaceind = i;
            }
        }
        return s;
    };
};